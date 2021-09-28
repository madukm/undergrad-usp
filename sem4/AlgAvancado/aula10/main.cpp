#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>

//Expects non null-terminated string, hence pat_size
int *pattern_enhancer(const char* pattern, size_t pat_size) //returns pattern enhancer
{
    int *ret = (int*) calloc(pat_size+1, sizeof(int));
    int pat_index = 0;
    int suffix_match = -1;
    ret[0] = -1;

    while (pat_index < pat_size) //Will run through vec.
    {
        while (suffix_match >= 0 && 
               pattern[pat_index] != pattern[suffix_match])
                    suffix_match = ret[suffix_match];
        pat_index++;
        suffix_match++;

        ret[pat_index] = suffix_match;
    }

    return ret;
}

std::vector<int> pattern_search(const char* pattern, int *enhancer, size_t pat_size, char* buf, size_t buf_size)
{
    std::vector<int> ret;

    int i = 0, j = 0;
    while (i < buf_size)
    {
        while(j >= 0 && buf[i] != buf[j])
            j = enhancer[j];

        i++; j++;

        if (j == pat_size) //This means no error occurred until now.
        {
			printf("O padrao foi encontrado na posicao %ld\n", i-j);	
            ret.push_back(i-j);
			j = enhancer[j];
        }
    }

    return ret;
}

int main()
{
    char* text = NULL;
    char* pattern = NULL;
    size_t t_len = 0, pat_len = 0;
    int *KMP_enh;
    std::vector<int> search_occurences;

    //getline(&text, &t_len, stdin);
    //getline(&pattern, &pat_len, stdin);

    scanf("%ms", &text);
    scanf("%ms", &pattern);

    //Since getline stores the \n character, we must remove it.
    
    t_len = strlen(text);
    pat_len = strlen(pattern);

    KMP_enh = pattern_enhancer(pattern, pat_len);

    search_occurences = pattern_search(pattern, KMP_enh, pat_len, text, t_len);

    for (int place : search_occurences)
        printf("O padrao foi encontrado na posicao %d\n", place);

    free(text);
    free(pattern);
    free(KMP_enh);

    return 0;
}
