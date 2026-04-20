#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>   // Used for PlaySound
#include <mmsystem.h>  // Windows multimedia functions
#pragma comment(lib, "winmm.lib")

#define MAX_SONGS 100  // Maximum number of songs in the playlist

// Structure to hold song details
struct Song {
    char title[100];
};

struct Song playlist[MAX_SONGS];
int totalSongs = 0;       // Total number of songs loaded
int currentSong = -1;     // Index of currently playing song
int isPaused = 0;         // 0 = playing, 1 = paused


