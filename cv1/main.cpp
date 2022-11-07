#include <stdio.h>

int test(int integerValue, float floatValue, double doubleValue)
{
    FILE *textFile;
    FILE *binFile;
    int readInteger;
    float readFloat;
    double readDouble;

    textFile = fopen("textFile.txt","r");
    binFile = fopen("binFile.DAT","rb+");

    fread(&readInteger, sizeof(readInteger), 1, binFile);
    fread(&readFloat, sizeof(readFloat), 1, binFile);
    fread(&readDouble, sizeof(readDouble), 1, binFile);

    fclose(textFile);
    if((readInteger != integerValue) || (readFloat != floatValue) || (readDouble != doubleValue)){
        return 10; // binary file failed
    }

    fclose(binFile);
    while (fscanf(textFile, "%d %f %lf", &readInteger, &readFloat, &readDouble) != EOF)
        if((readInteger != integerValue) || (readFloat != floatValue) || (readDouble != doubleValue)){
            return 11; // text file failed
        }

    return 0;
}

int main()
{
    int inputInteger;
    float inputFloat;
    double inputDouble;
    FILE *textFile;
    FILE *binFile;

    textFile = fopen("textFile.txt","w");
    binFile = fopen("binFile.DAT","wb+");

    printf("enter integer:");
    scanf("%d", &inputInteger);
    printf("enter float:");
    scanf("%f", &inputFloat);
    printf("enter double:");
    scanf("%lf", &inputDouble);

    fprintf(textFile,"%d %f %lf", inputInteger, inputFloat, inputDouble);
    fclose(textFile);

    fwrite(&inputInteger, sizeof(inputInteger), 1, binFile);
    fwrite(&inputFloat, sizeof(inputFloat), 1, binFile);
    fwrite(&inputDouble, sizeof(inputDouble), 1, binFile);
    fclose(binFile);

    return test(inputInteger, inputFloat, inputDouble);
}
