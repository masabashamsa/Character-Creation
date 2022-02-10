FILE *fa
int main(){ 

fa = fopen(attemptsUrl,"r");

                            char a_id[10];
                            char a_date[30];
                            char a_score[10];
                            char a_time[10];
                            char a_comment[100];
                            int date_seconds;
                            time_t date;
                            int a_attempted=0;
                            int not_attempted=0;

                            if (!fa)
                            {
                                printf("\nYou have not yet attempted any assignments");
            
                            }

                            
                            printf("=======================================Attempted assignments=================================================================\n");
                            
                            while (fscanf(fa, "%s %s %s %s %[^\n]*", a_id, a_date, a_score, a_time, a_comment) > 0)
                            {
                                date_seconds = atoi(a_date);
                                date = date_seconds;
                                printf(" id: %s\n Average score: %s\n Time took: %s(s)\n Teacher's comment: %s\n Done on: %s\n", a_id, a_score, a_time, a_comment, asctime(gmtime(&date)));
                                a_attempted = a_attempted + 1;
                                printf("========================================================================================================\n");
                            }
                            fclose(fa);
                            printf("=======================================Assignments not yet attempted=================================================================\n");
                            ///attempted assignments
                            fa = fopen(assignmentUrl, "r");
                            while (fscanf(fa, "%s %s %s %s %s %s %s %s %s %s %s %s %s", id, startDate, startTime, endDate, endTime, a, b, c, d, e, f, g, h) > 0)
                            {
                                not_attempted = not_attempted +1;
                                printf("id:%s startDate: %s  startTime: %s endtDate: %s  endTime: %s  %s %s %s %s %s %s %s %s\n", &id, startDate, startTime, endDate, endTime, a, b, c, d, e, f, g, h);

                            }
                            fclose(fa);
                            printf("You have attempted:%d\n You are left with:%d\n", a_attempted, not_attempted);
                            break;
}