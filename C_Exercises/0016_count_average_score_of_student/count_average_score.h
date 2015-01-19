/*************************************************************************
    > File Name: count_average_score.h
    > Author: Sam Wong
    > Mail: ncepuwanghui@gmail.com 
    > Blog: http://samwong.im 
    > Created Time: Sun 18 Jan 2015 08:32:51 PM CST
 ************************************************************************/

#ifndef COUNT_AVERAGE_SCORE_H_
#define COUNT_AVERAGE_SCORE_H_

#define COURSE_NUM 5 //共有5门课程

struct score_info
{
    int stu_id;
    double scores[COURSE_NUM];
    double avg_score;
    struct score_info *next;
};

struct score_list
{
    struct score_info *list;
    int size;
};

typedef struct score_list *

void init_score_list(struct score_list *);
void destroy_score_list(score_list *list);

void read_score_from_file(score_list *list, int *record_num, const char *score_file);

void write_rank_to_file(score_list *list, const char *rank_file);

void add_score_to_list(score_list *list, pscore *new_record, int *record_num);

void sort_score_list(score_list *list);


#endif
