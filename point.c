/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:39:43 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/07 09:39:45 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// 座標圧縮を行う関数
int* compress(int argc, char* argv[]) {
    int i, j, tmp;
    int* arg_int = (int*)malloc(sizeof(int) * (argc - 1)); // 引数を整数に変換したものを格納する配列
    int* index = (int*)malloc(sizeof(int) * (argc - 1)); // 圧縮後のインデックスを格納する配列

    // 引数を整数に変換してarg_intに格納する
    for (i = 1; i < argc; i++) {
        arg_int[i - 1] = atoi(argv[i]);
    }

    // arg_intを昇順にソートする
    for (i = 0; i < argc - 1; i++) {
        for (j = i + 1; j < argc - 1; j++) {
            if (arg_int[i] > arg_int[j]) {
                tmp = arg_int[i];
                arg_int[i] = arg_int[j];
                arg_int[j] = tmp;
            }
        }
    }

    // 圧縮後のインデックスを計算する
    j = 0;
    for (i = 0; i < argc - 1; i++) {
        if (i == 0 || arg_int[i] != arg_int[i - 1]) {
            index[j] = arg_int[i];
            j++;
        }
    }

    // 圧縮後のインデックスを出力する
    for (i = 0; i < argc - 1; i++) {
        for (j = 0; j < argc - 1; j++) {
            if (arg_int[i] == index[j]) {
                printf("%d ", j + 1); // 圧縮後のインデックスを出力する
                break;
            }
        }
    }
    printf("\n");

    free(arg_int);
    return index;
}

int main(int argc, char* argv[]) {
    int* index = compress(argc, argv);

    // 圧縮後のインデックスを出力する
    int i;
    for (i = 0; i < argc - 1; i++) {
        printf("%d ", index[i]);
    }
    printf("\n");

    free(index);
    return 0;
}