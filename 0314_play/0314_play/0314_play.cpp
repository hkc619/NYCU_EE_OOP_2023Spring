// 0314_play.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <windows.h>
#include "CAudio.h"
#include <conio.h>

typedef struct wav_header {
    // RIFF Header
    char riff_header[4]; // Contains "RIFF"
    int wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
    char wave_header[4]; // Contains "WAVE"

    // Format Header
    char fmt_header[4]; // Contains "fmt " (includes trailing space)
    int fmt_chunk_size; // Should be 16 for PCM
    short audio_format; // Should be 1 for PCM. 3 for IEEE Float
    short num_channels;
    int sample_rate;
    int byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
    short sample_alignment; // num_channels * Bytes Per Sample
    short bit_depth; // Number of bits per sample

    // Data
    char data_header[4]; // Contains "data"
    int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    // uint8_t bytes[]; // Remainder of wave file is bytes
} wav_header;

CAudio* lp;//放音物件
FILE* In;//檔案指標
int g_No = 0;//全域變數
void CALLBACK Play_Proc(HWAVEIN hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
    // 存聲音
    int Len = 160;
    short Speech[160];
    switch (uMsg)
    {
    case WOM_DONE:
        if (lp->PStart)
        {
            if(In!=NULL)//讀取160 sample data
                fread(Speech, 2, 160, In);
           
            if (feof(In))
                fseek(In, 0, 0);//當讀到檔案尾巴，reset到檔頭再繼續讀
            lp->Play_Speech(Speech, Len);
            g_No += Len;
            //if ((Out != 0) && (Len == 160)) fwrite(Speech, Len, sizeof(short), Out);
            printf("%d\r", g_No++);
        }
        break;
    }
}

int main()
{
    //0. 生成錄放音物件
    lp = new CAudio();

    //1. play sound(..)
    lp->USB_PlayDisconnectTone(0);
    
    //2. play pcm file
    //2.2 開啟檔案
    errno_t err;
    wav_header buf;
    if ((err = fopen_s(&In, "1.wav","rb"))!=0)
    {
        printf("File error\n");
        return 0;
    }
    fread(&buf, 1, sizeof(wav_header), In);
    printf("sample rate =%d\n", buf.sample_rate);
    printf("channel     =%d\n", buf.num_channels);
    printf("bits/sample =%d\n", buf.bit_depth);
    //2.5 啟動放音
    lp->Init_Audio(160, -1, -1, buf.sample_rate, buf.num_channels); //160SAMPLES = 20MS = 放音BUFFER的大小
    lp->Open_Play((DWORD)Play_Proc, CALLBACK_FUNCTION);
    lp->Start_Play();

    //3. play wav file
    char a = _getch();

    //4.結束放音
    lp->Stop_Play();
    lp->Close_Play();
}

