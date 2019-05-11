#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#include "helpers.h"

// fraction formatted as X/Y to eighths

int duration(string fraction)
{

    // TODO

    int beat = fraction[0] -'0';
    int count = fraction[2]-'0';

    return ((16 / count) * beat/2);
}


// Calculates frequency (in Hz) of a note

int frequency(string note)

{

    char note_letter = note[0];

    char octave = note[strlen(note) - 1];

    // CHECKING IF NOTE INPUT IS BETWEEN RANGES AVAILABLE ON A KEYBOARD
    if ((note_letter < 'A' || note_letter > 'G' ) || (octave < '0' || octave > '8'))
        return 1;

    int middle_hz = 440; //STARTING POINT FOR MIDDLE A
    int full_step = (octave - '4'); //CHECKS DISTANCE OF OCTAVE WITH MID 'A'
    int hz = round(middle_hz * pow(2, full_step));
    float a = 0., b = 2., c = -9., d = -7., e = -5., f = -4., g = -2.; //STEPS BETWEEN SEMITONES ON KEYS

    int freq;
    float x;

    switch (note_letter)
    {
        case 'A':
        x = a;
        break;

        case 'B':
        x = b;
        break;

        case 'C':
        x = c;
        break;

        case 'D':
        x = d;
        break;

        case 'E':
        x = e;
        break;

        case 'F':
        x = f;
        break;

        case 'G':
        x = g;
        break;

        default:
        return 1;
    }

    int raw_hz = round(hz * pow(2, x/12));
    int res = (hz * pow(2, x/12));

    if (note[1] == '#')
    {
        freq = round(res * pow(2., 1./12.));
        return (freq);
    }
    else if (note[1] == 'b')
    {
        freq = round(res / pow(2., 1./12.));
        return (freq);
    }
    return (raw_hz);
}



bool is_rest(string s)
{

    // TODO

    if (s[0] == '\0')
    {
        return true;
    }
    return false;

}
