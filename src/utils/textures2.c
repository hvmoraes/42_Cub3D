/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:13:29 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/28 11:13:29 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char *remove_el(char *line) {
    char *new_line;
    int i = 0;
    int j = 0;

    new_line = malloc((ft_strlen(line) + 1) * sizeof(char));
    if (new_line == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    while (line[i]) {
        if (line[i] == '\n') {
            new_line[j] = '\0';  // Replace newline with null terminator
            break;
        }
        new_line[j] = line[i];
        i++;
        j++;
    }
    // Ensure the copied string is null-terminated
    new_line[j] = '\0';
    free(line);  // Free the memory allocated for the original line
    printf("\n.%s.\n", new_line);
    return new_line;
}
