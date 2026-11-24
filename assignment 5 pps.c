#include <stdio.h>
#include <string.h>

int main() {
    char s[100], str2[100], ch;
    char *ptr;
    int choice, n;

    do {
        printf("\n--- STRING OPERATIONS MENU ---\n");
        printf("1. Find length\n");
        printf("2. Copy string\n");
        printf("3. Concatenate string\n");
        printf("4. Compare string\n");
        printf("5. Search for a character\n");
        printf("6. Search for substring\n");
        printf("7. Reverse a string\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]", s);
                n = strlen(s);
                printf("Length of string = %d\n", n);
                break;

            case 2:
                printf("Enter source string: ");
                scanf(" %[^\n]", s);
                strcpy(str2, s);
                printf("Copied string = %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                scanf(" %[^\n]", s);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                strcat(s, str2);
                printf("Concatenated string = %s\n", s);
                break;

            case 4:
                printf("Enter first string: ");
                scanf(" %[^\n]", s);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                n = strcmp(s, str2);
                if (n == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal (Difference = %d).\n", n);
                break;

            case 5:
                printf("Enter a string: ");
                scanf(" %[^\n]", s);
                printf("Enter character to search: ");
                scanf(" %c", &ch);
                ptr = strchr(s, ch);
                if (ptr != NULL)
                    printf("Character '%c' found at position: %ld\n", ch, (ptr - s) + 1);
                else
                    printf("Character not found.\n");
                break;

            case 6:
                printf("Enter main string: ");
                scanf(" %[^\n]", s);
                printf("Enter substring to search: ");
                scanf(" %[^\n]", str2);
                ptr = strstr(s, str2);
                if (ptr != NULL)
                    printf("Substring \"%s\" found at position: %ld\n", str2, (ptr - s) + 1);
                else
                    printf("Substring not found.\n");
                break;

            case 7:
                printf("Enter a string: ");
                scanf(" %[^\n]", s);
                strrev(s);
                printf("Reversed string = %s\n", s);
                break;

            case 8:
                printf("Enter a string: ");
                scanf(" %[^\n]", s);
                strupr(s);
                printf("Uppercase string = %s\n", s);
                break;

            case 9:
                printf("Enter a string: ");
                scanf(" %[^\n]", s);
                strlwr(s);
                printf("Lowercase string = %s\n", s);
                break;

            case 10:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 10);

    return 0;
}
