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


void loadSongs();// Functions Declaraations
void showPlaylist();
void playSong(int index);
void pausePlayback();
void continuePlayback();
void playNext();
void playPrevious();

int main() {
    int choice;

    // Load fixed songs into memory at the start
    loadSongs();

    while (1) {
        printf("\n==== SIMPLE PLAYLIST MANAGER ====\n");
        printf("1. Show Playlist\n");
        printf("2. Play a Song\n");
        printf("3. Pause Song\n");
        printf("4. Continue Song\n");
        printf("5. Next Song\n");
        printf("6. Previous Song\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch (choice) {
            case 1:
                showPlaylist();
                break;

            case 2: {
                showPlaylist();
                int songNum;
                printf("Enter the song number to play: ");
                scanf("%d", &songNum);
                getchar();

                if (songNum >= 1 && songNum <= totalSongs)
                    playSong(songNum - 1);
                else
                    printf("Invalid song number. Try again!\n");
                break;
            }

            case 3:
                pausePlayback();
                break;

            case 4:
                continuePlayback();
                break;

            case 5:
                playNext();
                break;

            case 6:
                playPrevious();
                break;

            case 7:
                printf("Closing player... See you again!\n");
                PlaySound(NULL, 0, 0);
                exit(0);

            default:
                printf("Invalid input! Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}

// Loads the fixed set of songs into the playlist
void loadSongs() {
    strcpy(playlist[0].title, "salaar.wav");
    strcpy(playlist[1].title, "sahiba.wav");
    strcpy(playlist[2].title, "devara.wav");
    strcpy(playlist[3].title, "beast.wav");
    strcpy(playlist[4].title, "animal.wav");
    totalSongs = 5;
}

// Displays all songs in the playlist
void showPlaylist() {
    printf("\n------ PLAYLIST ------\n");
    for (int i = 0; i < totalSongs; i++) {
        if (i == currentSong && !isPaused)
            printf("▶ %d. %s (Playing)\n", i + 1, playlist[i].title);
        else if (i == currentSong && isPaused)
            printf("⏸ %d. %s (Paused)\n", i + 1, playlist[i].title);
        else
            printf("   %d. %s\n", i + 1, playlist[i].title);
    }
}

// Plays the selected song
void playSong(int index) {
    if (index < 0 || index >= totalSongs) {
        printf("Invalid song index!\n");
        return;
    }

    currentSong = index;
    isPaused = 0;

    char filePath[200];
    sprintf(filePath, "playlist\\%s", playlist[index].title);

    printf("Now playing: %s ...\n", playlist[index].title);
    PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);
}

// Pauses the current song
void pausePlayback() {
    if (currentSong == -1) {
        printf("No song is currently playing.\n");
        return;
    }

    if (isPaused) {
        printf("Song is already paused.\n");
        return;
    }


    // Continues the paused song
void continuePlayback() {
    if (currentSong == -1) {
        printf("No song to continue.\n");
        return;
    }

    if (!isPaused) {
        printf("Song is already playing.\n");
        return;
    }

    isPaused = 0;
    char filePath[200];
    sprintf(filePath, "playlist\\%s", playlist[currentSong].title);
    printf("Resuming: %s ...\n", playlist[currentSong].title);
    PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);
}

// Moves to the next song in the playlist
void playNext() {
    if (totalSongs == 0) {
        printf("No songs available in the playlist.\n");
        return;
    }

    currentSong = (currentSong + 1) % totalSongs;
    playSong(currentSong);
}

// Moves back to the previous song
void playPrevious() {
    if (totalSongs == 0) {
        printf("No songs available in the playlist.\n");
        return;
    }

    currentSong = (currentSong - 1 + totalSongs) % totalSongs;
    playSong(currentSong);
}

    isPaused = 1;
    PlaySound(NULL, 0, 0); // stops the sound temporarily
    printf("Song paused: %s\n", playlist[currentSong].title);
}
