#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define PageFrames 500



typedef struct Page{
    int page_frame_number;
    unsigned int  lifespan;
    int caching_disable;
    int modified;
    int protection;
    int present;
} Page;

Page create_page(int number){
    Page p;
    p.lifespan = 0;
    p.page_frame_number = number;
    p.modified = 0; // 0 = not modified at the beginning
    p.caching_disable = 0; // 0 = not turn off, 1 = turn off
    p.protection = 0; // you can write and read
    p.present = 0; // create a page and set bit to 0
    return p;
}
typedef struct PageTable{
    Page * p;
    int array [PageFrames];
    int Miss;
    int Hit;
} PageTable;

PageTable create_page_table(int count){
    PageTable table;
    table.p = malloc(count*sizeof(Page));
    for ( int i = 0; i < 1000; i ++){

        table.p[i] = create_page(i);
    }
    table.Miss = 0;
    table.Hit = 0;
    for (int i = 0; i < PageFrames; i ++){
        table.array[i] = -1;
    }
    return table;
}

PageTable ageing() {
    PageTable table = create_page_table(1000);
    int ch;
    int *file_name;
    FILE *fp;
    fp = fopen("lab.txt", "r");
    int count = 0;
    while (fscanf(fp, "%d", &ch) == 1) {
        if (table.p[ch].present == 0) {
            table.Hit = table.Hit + 1;
            table.Miss = table.Miss + 1;
            if (count < PageFrames) {
                table.p[ch].page_frame_number = count;
                table.p[ch].present = 1;
                for ( int i = 0; i<PageFrames; i ++){
                    if (table.array[i] != -1)
                        table.p[table.array[i]].lifespan = table.p[table.array[i]].lifespan>>1;

                }

                table.p[ch].lifespan = table.p[ch].lifespan + (1<<3);
                table.array[count] = ch;
                count++;
            }
            else if(count >= PageFrames){
                for ( int i = 0; i < PageFrames;  i ++){
                    if (table.p[table.array[i]].lifespan == 0) {
                        table.p[table.array[i]].present = 0;
                        table.p[ch].page_frame_number = count;
                        for ( int j = 0; j<PageFrames; j ++){
                            if (table.array[j] != -1)
                            table.p[table.array[j]].lifespan = table.p[table.array[j]].lifespan>>1;
                        }
                        table.p[ch].lifespan = table.p[ch].lifespan + (1<<3);
                        table.array[i] = ch;
                        table.p[ch].present = 1;
                        break;

                    }
                }
            }
        }
        else if ( table.p[ch].present == 1){
            table.Hit = table.Hit + 1;
            for ( int i = 0; i<PageFrames; i++){
                if (table.array[i] != -1)
                table.p[table.array[i]].lifespan = table.p[table.array[i]].lifespan>>1;
            }
            table.p[ch].lifespan = table.p[ch].lifespan + (1<<3);
            table.array[count] = ch;
        }

    }
    return table;
}


int main() {
    PageTable table = ageing();
    printf("Hit: %d\n", table.Hit);
    printf("Miss: %d\n", table.Miss);
    printf("Hit/Miss Ratio: %f", (double)table.Hit/table.Miss);
    return 0;
}