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

// source: https://pianoletternotes.blogspot.com/2017/10/carol-of-bells.html
int carol_of_the_bells_notes[] = {
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_AS4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_AS4, NOTE_D5,
  NOTE_C5, NOTE_D5, NOTE_AS4, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_AS4, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_AS4,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_G4,
  NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_D4, NOTE_E4,
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_AS4
};
int carol_of_the_bells_tempos[] = {
  4, 2, 2, 4, 4, 2, 2, 4, 4, 2, 2, 4, 4, 2, 2, 4, 4, 2, 2, 4, 4, 2, 2,
  4, 4, 2, 2, 4, 4, 2, 2, 4, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2, 4, 2, 2, 2,
  2, 4, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2,
  4, 4
};

// source: https://pianoletternotes.blogspot.com/2017/10/last-christmas-by-wham.html
int last_christmas_notes[] = {
  NOTE_G5, NOTE_G5, NOTE_F5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5,
  NOTE_F5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_A5, NOTE_G5,
  NOTE_D5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_C5
};
int last_christmas_tempos[] = {
  6, 4, 4, 2, 2, 2, 2, 6, 2, 2, 2, 2, 4, 6, 2, 2, 2, 2, 10, 6, 8, 2,
  2, 2, 2, 8, 2, 2, 2, 2, 4, 4, 4, 16
};

// source: https://pianoletternotes.blogspot.com/2018/12/joy-to-world-by-isaac-watts.html
// int joy_to_the_world_notes[] = {
//   NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4,
//   NOTE_D4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_CS5, NOTE_D5,
//   NOTE_D5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4,
//   NOTE_FS4, NOTE_D5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4,
//   NOTE_G4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4,
//   NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_E4, NOTE_E4,
//   NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_D5,
//   NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4,
//   NOTE_D4
// };
// int joy_to_the_world_tempos[] = {
//   4, 3, 1, 6, 2, 4, 4, 6, 2, 6, 2, 6, 2, 14, 2, 2, 2, 2, 2, 3, 1, 2,
//   2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 1, 1, 6, 1, 1, 2, 2, 2, 1, 1, 6,
//   1, 1, 2, 4, 2, 3, 1, 2, 2, 4, 4, 4
// };

// source: https://pianoletternotes.blogspot.com/2017/10/greensleeves.html
// int greensleeves_notes[] = {
//   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5,
//   NOTE_B4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_A4,
//   NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_GS4, NOTE_E4, NOTE_A4, NOTE_C5,
//   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_G4,
//   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_FS4,
//   NOTE_GS4, NOTE_A4, NOTE_A4, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_E5,
//   NOTE_D5, NOTE_B4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4,
//   NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_GS4, NOTE_E4, NOTE_G5,
//   NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_G4, NOTE_A4,
//   NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_FS4, NOTE_GS4,
//   NOTE_A4, NOTE_A4
// };
// int greensleeves_tempos[] = {
//   2, 4, 2, 3, 1, 2, 4, 2, 3, 1, 2, 4, 2, 3, 1, 2, 4, 2, 4, 2, 4, 2, 3,
//   1, 2, 4, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 6, 6, 6, 3, 1, 2, 4, 2, 3, 1,
//   2, 4, 2, 3, 1, 2, 4, 2, 6, 6, 3, 1, 2, 4, 2, 3, 1, 2, 3, 1, 2, 3, 1,
//   2, 6, 20
// };

// source: https://pianoletternotes.blogspot.com/2015/11/silent-night-by-franz-gruber.html
// int silent_night_notes[] = {
//   NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4,
//   NOTE_E4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_G4,
//   NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4,
//   NOTE_G4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4,
//   NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D5, NOTE_D5, NOTE_F5,
//   NOTE_D5, NOTE_B4, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G4, NOTE_E4,
//   NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4, NOTE_C4
// };
// int silent_night_tempos[] = {
//   6, 2, 4, 12, 6, 2, 4, 12, 8, 4, 12, 8, 4, 12, 8, 4, 6, 2, 4, 6, 2,
//   4, 12, 8, 4, 6, 2, 4, 6, 2, 4, 12, 8, 4, 6, 2, 4, 12, 12, 6, 2, 4,
//   6, 2, 4, 12, 12
// };

// source: https://pianoletternotes.blogspot.com/2018/12/go-tell-it-on-mountain.html
// int go_tell_it_on_the_mountain_notes[] = {
//   NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_A3, NOTE_D4,
//   NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_E4,
//   NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_D4,
//   NOTE_B3, NOTE_A3, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_FS4,
//   NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_A4,
//   NOTE_B4, NOTE_A4, NOTE_FS4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4,
//   NOTE_E4, NOTE_FS4, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_A4, NOTE_B4,
//   NOTE_A4, NOTE_FS4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_B3,
//   NOTE_A3, NOTE_G4, NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_B3,
//   NOTE_A3, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4,
//   NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_D4
// };
// int go_tell_it_on_the_mountain_tempos[] = {
//   8, 2, 2, 2, 2, 8, 8, 2, 4, 2, 4, 4, 2, 2, 2, 2, 8, 8, 2, 2, 2, 2, 8,
//   4, 4, 4, 4, 2, 2, 4, 12, 4, 4, 4, 6, 2, 4, 8, 4, 4, 4, 4, 4, 12, 4,
//   4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 8, 8, 8, 2, 2, 2, 2, 8, 8, 2, 4, 2,
//   4, 4, 2, 2, 2, 2, 8
// };

// source: https://pianoletternotes.blogspot.com/2018/12/jingle-bell-rock-by-bobby-helms.html
// int jingle_bell_rock_notes[] = {
//   NOTE_C5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4,
//   NOTE_B4, NOTE_A4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_E4,
//   NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_E4,
//   NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_F4,
//   NOTE_G4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_A4,
//   NOTE_DS4, NOTE_DS4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_B4,
//   NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_E4, NOTE_A4, NOTE_B4,
//   NOTE_A4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4,
//   NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4,
//   NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_G4,
//   NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5,
//   NOTE_A4, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5,
//   NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C5, NOTE_C5, NOTE_C5,
//   NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G4,
//   NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4,
//   NOTE_G4
// };
// int jingle_bell_rock_tempos[] = {
//   2, 2, 4, 2, 2, 4, 2, 2, 2, 10, 2, 2, 4, 4, 4, 2, 2, 4, 8, 2, 4, 2,
//   2, 4, 2, 2, 2, 4, 12, 2, 2, 2, 2, 4, 4, 2, 10, 2, 2, 4, 2, 2, 4, 2,
//   2, 2, 10, 2, 2, 4, 4, 4, 2, 2, 4, 8, 2, 4, 2, 2, 4, 2, 2, 2, 4, 12,
//   2, 2, 2, 4, 2, 12, 2, 2, 2, 4, 6, 2, 2, 2, 4, 8, 2, 4, 4, 4, 4, 12,
//   2, 2, 2, 4, 6, 2, 2, 6, 12, 2, 4, 2, 2, 2, 2, 2, 4, 10
// };

// source: https://pianoletternotes.blogspot.com/2018/04/auld-lang-syne.html
int auld_lang_syne_notes[] = {
  NOTE_C4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_D4,
  NOTE_C4, NOTE_F4
};
int auld_lang_syne_tempos[] = {
  4, 6, 2, 4, 4, 6, 2, 4, 2, 2, 6, 2, 4, 4, 12, 4, 6, 2, 4, 4, 6, 2,
  4, 2, 2, 6, 2, 4, 4, 14
};

// source: https://pianoletternotes.blogspot.com/2017/10/dance-of-sugar-plum-fairy-nutcracker.html
// int nutcracker_notes[] = {
//   NOTE_F6, NOTE_D6, NOTE_F6, NOTE_E6, NOTE_CS6, NOTE_D6, NOTE_C6,
//   NOTE_C6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_AS5, NOTE_AS5,
//   NOTE_AS5, NOTE_A5, NOTE_D6, NOTE_AS5, NOTE_D6, NOTE_A5, NOTE_D5,
//   NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_F5, NOTE_D5, NOTE_F5,
//   NOTE_E5, NOTE_AS5, NOTE_A5, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_E6,
//   NOTE_E6, NOTE_E6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_CS6, NOTE_E6,
//   NOTE_D6, NOTE_E6, NOTE_CS6, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4,
//   NOTE_D4
// };
// int nutcracker_tempos[] = {
//   2, 2, 4, 4, 4, 4, 2, 2, 4, 2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 4, 1, 1, 1,
//   1, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 4, 1,
//   1, 1, 1, 1
// };

// source: https://pianoletternotes.blogspot.com/2017/10/deck-halls.html
int deck_the_halls_notes[] = {
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_B3, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4,
  NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4
};
int deck_the_halls_tempos[] = {
  6, 2, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 6, 2, 4, 4, 8, 6, 2, 4, 4, 4, 4,
  4, 4, 2, 2, 2, 2, 6, 2, 4, 4, 8, 6, 2, 4, 4, 6, 2, 4, 4, 2, 2, 4, 2,
  2, 4, 4, 4, 8, 6, 2, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 6, 2, 4, 4, 12
};

// source: https://pianoletternotes.blogspot.com/2018/12/ding-dong-merrily-on-high.html
int dingdong_notes[] = {
  NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_AS4,
  NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_D5, NOTE_DS5,
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,
  NOTE_AS4, NOTE_C5, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4,
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_AS4
};
int dingdong_tempos[] = {
  4, 4, 2, 2, 2, 2, 12, 4, 4, 4, 4, 4, 8, 8, 4, 4, 2, 2, 2, 2, 12, 4,
  4, 4, 4, 4, 8, 8, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2,
  2, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 2, 4, 4, 4, 4, 4, 4, 8, 8
};


void playChristmasSong(int song_id, int note_duration)
{
    Song jingleBells = Song(jingleBells_notes, jingleBells_tempos, sizeof(jingleBells_notes) / sizeof(int));
    Song wishYouAMerry = Song(wish_notes, wish_tempos, sizeof(wish_notes) / sizeof(int));
    Song auldLangSyne = Song(auld_lang_syne_notes, auld_lang_syne_tempos, sizeof(auld_lang_syne_notes) / sizeof(int));
    Song deckTheHalls = Song(deck_the_halls_notes, deck_the_halls_tempos, sizeof(deck_the_halls_notes) / sizeof(int));
    Song lastChristmas = Song(last_christmas_notes, last_christmas_tempos, sizeof(last_christmas_notes) / sizeof(int));
    Song carolOfTheBells = Song(carol_of_the_bells_notes, carol_of_the_bells_tempos, sizeof(carol_of_the_bells_notes) / sizeof(int));
 
  
  
    // Song santaClausComing = Song(santa_notes, santa_tempos, sizeof(santa_notes) / sizeof(int));
    // Song joyToTheWorld = Song(joy_to_the_world_notes, joy_to_the_world_tempos, sizeof(joy_to_the_world_notes) / sizeof(int));
    // Song greensleeves = Song(greensleeves_notes, greensleeves_tempos, sizeof(greensleeves_notes) / sizeof(int));
    // Song silentNight = Song(silent_night_notes, silent_night_tempos, sizeof(silent_night_notes) / sizeof(int));
    // Song goTellItOnTheMountain = Song(go_tell_it_on_the_mountain_notes, go_tell_it_on_the_mountain_tempos, sizeof(go_tell_it_on_the_mountain_notes) / sizeof(int));
    // Song jingleBellRock = Song(jingle_bell_rock_notes, jingle_bell_rock_tempos, sizeof(jingle_bell_rock_notes) / sizeof(int));
    // Song nutcracker = Song(nutcracker_notes, nutcracker_tempos, sizeof(nutcracker_notes) / sizeof(int));
    // Song dingDong = Song(dingdong_notes, dingdong_tempos, sizeof(dingdong_notes) / sizeof(int));


    Song songs[] = {
        jingleBells,
        wishYouAMerry,
        auldLangSyne,
        deckTheHalls,
        lastChristmas

        // joyToTheWorld,
        // jingleBellRock,
        // santaClausComing, 
        // dingDong,
        // deckTheHalls,
        // // nutcracker,
        // auldLangSyne,
        // goTellItOnTheMountain,
        // greensleeves,
        // lastChristmas
        };

    // TODO: we will need 19 songs for the 19 levels, but without
    // further optimization they won't fit into memory
    songs[song_id % 5].play(note_duration);
}