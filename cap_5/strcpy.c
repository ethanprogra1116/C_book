

int main() {


    return 0;
}

// Implementaciones de strcpy

// Con array
void arrcpy(char *og,  char *md) {
    int i = 0;
    while ((og[i] = md[i]) != '\0')
        i++;
}

void pcopy(char *og,  char *md) {
    while ((*og = *md) != '\0') {
        og++;
        md++;
    }
}

void effcopy(char *og,  char *md) {
    while ((*og++ = *md++))
        ;
}
