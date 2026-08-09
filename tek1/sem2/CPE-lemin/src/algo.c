/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** algo
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void dijkstra(Graph* graph, int start_node, int end_node)
{
    int num_nodes = graph->num_nodes;
    int dist[num_nodes];
    int visited[num_nodes];
    int parent[num_nodes];
    for (int i = 0; i < num_nodes; i = i + 1) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start_node] = 0;
    for (int i = 0; i < num_nodes - 1; i = i + 1) {
        int u = min_distance(dist, visited, num_nodes);
        visited[u] = 1;
*        Node* node = graph->adj_list[u];
        while (node != 0) {
            int v = node->id;
            int weight = node->weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
            node = node->next;
        }
    }
    printf("Shortest path from %d to %d: ", start_node, end_node);
    print_path(parent, end_node);
    my_putchar("\n");
}
