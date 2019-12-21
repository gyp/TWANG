#include "toneAC.h"
#include "pitches.h"

class Song {
    public:
        int *notes;
        int *tempos;
        int length;

        Song(int _notes[], int _tempos[], int _length)
        {
            notes = (int*) malloc(sizeof(int) * _length);
            tempos = (int*) malloc(sizeof(int) * _length);
            Serial.println("SONG INIT");
            for (int i = 0; i < _length; i++)
            {
                notes[i] = _notes[i];
                tempos[i] = _tempos[i];
            }
            length = _length;
        }

        void play(int beat_length) {
            Serial.println("PLAY CALLED");
            int beat_gap = beat_length / 3;

            for (int i = 0; i < length; i++)
            {
                // Serial.println("---");
                // Serial.println(i);
                // Serial.println(notes[i]);
                // Serial.println(tempos[i]);

                toneAC(notes[i]);
                delay(beat_length * tempos[i] - beat_gap);
                noToneAC();
                delay(beat_gap);
            }            
        }
};


int jingleBells_notes[] = {
NOTE_E5, NOTE_E5, NOTE_E5,
NOTE_E5, NOTE_E5, NOTE_E5,
NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
NOTE_E5,
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
NOTE_D5, NOTE_G5
};

int jingleBells_tempos[] = {
2, 2, 4,
2, 2, 4,
2, 2, 2, 2,
8,
2, 2, 2, 2,
2, 2, 2, 1, 1,
2, 2, 2, 2,
4, 4
};

// We wish you a merry Christmas
int wish_notes[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempos[] = {
  4,
  4, 2, 2, 2, 2,
  4, 4, 4,
  4, 2, 2, 2, 2,
  4, 4, 4,
  4, 2, 2, 2, 2,
  4, 4, 2, 2,
  4, 4, 4,
  8
};


// Santa Claus is coming to town
int santa_notes[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempos[] = {
  2,
  2, 2, 4, 4, 4,
  2, 2, 4, 4, 4,
  2, 2, 4, 4, 4,
  2, 2, 4, 8,
  4, 4, 4, 4,
  4, 8, 4,
  16
};

void playChristmasSong(int song_id, int note_duration)
{
    Song jingleBells = Song(jingleBells_notes, jingleBells_tempos, sizeof(jingleBells_notes) / sizeof(int));
    Song wishYouAMerry = Song(wish_notes, wish_tempos, sizeof(wish_notes) / sizeof(int));
    Song santaClausComing = Song(santa_notes, santa_tempos, sizeof(santa_notes) / sizeof(int));

    Song songs[] = {jingleBells, wishYouAMerry, santaClausComing};

    songs[song_id % (sizeof(songs) / sizeof(Song))].play(note_duration);
}