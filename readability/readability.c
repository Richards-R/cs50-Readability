// Grade text passages according to Coleman-Liau index
// "index = 0.0588 * L - 0.296 * S - 15.8"
// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text

// what finishes a word - space
// what finishes a sentence - full stop, exclamation mark, question mark

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int sent_count = 0;
    int word_count = 1;
    int lett_count = 0;
    string letters = "abcdefghijklmnopqrstuvwxyz";

    string text_input = get_string("Text: ");

    // Loop through input to count sentences, words, letters
    for (int i = 0, n = strlen(text_input); i < n; i++)
    {
        if (text_input[i] == 46 || text_input[i] == 33 || text_input[i] == 63)
        {
            sent_count++;
        }

        if (text_input[i] == 32)
        {
            word_count++;
        }

        for (int j = 0, m = strlen(letters); j < m; j++)
        {
            char text_input_test_letter = tolower(text_input[i]);

            if (text_input_test_letter == letters[j])
            {
                lett_count++;
            }
        }
    }

    // Construct Coleman–Liau index formula
    float l = ((float) lett_count / word_count) * 100;
    float s = ((float) sent_count / word_count) * 100;

    float index = round(0.0588 * l - 0.296 * s - 15.8);

    // Produce output dependent on Grade score
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) index);
    }
}
