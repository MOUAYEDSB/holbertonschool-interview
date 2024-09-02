#include <stdlib.h>
#include <string.h>
#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int len_s = strlen(s);
int word_len = strlen(words[0]);
int total_len = word_len * nb_words;
int *indices = NULL;
int count = 0;

if (len_s < total_len) {
	*n = 0;
	return NULL;
}

indices = malloc(len_s * sizeof(int));

for (int i = 0; i <= len_s - total_len; i++) {
	int seen[nb_words];
	memset(seen, 0, sizeof(seen));

	for (int j = 0; j < nb_words; j++) {
		int found = 0;
		for (int k = 0; k < nb_words; k++) {
			if (!seen[k] && strncmp(s + i + j * word_len, words[k], word_len) == 0) {
				seen[k] = 1;
				found = 1;
				break;
			}
		}
		if (!found) {
			break;
		}
	}

	// Check if all words were matched
        int all_matched = 1;
        for (int j = 0; j < nb_words; j++) {
            if (!seen[j]) {
                all_matched = 0;
                break;
            }
        }

        if (all_matched) {
            indices[count++] = i;
        }
    }

    if (count == 0) {
        free(indices);
        *n = 0;
        return NULL;
    }

    indices = realloc(indices, count * sizeof(int));
    *n = count;

    return indices;
}
