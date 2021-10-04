#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
typedef void* seqQueue;
seqQueue init_SeqQueue();
void push_SeqQueue(seqQueue queue, void* data);
void pop_SeqQueue(seqQueue queue);
void* back_SeqQueue(seqQueue queue);
int size_SeqQueue(seqQueue queue);
void destory_SeqQueue (seqQueue queue);
