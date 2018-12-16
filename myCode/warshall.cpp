int V, E; scanf("%d %d", &V, &E);
for (int i = 0; i < V; i++) {
  for (int j = 0; j < V; j++)
    AM[i][j] = INF;
  AM[i][i] = 0;
}

for (int i = 0; i < E; i++) {
  int u, v, w; scanf("%d %d %d", &u, &v, &w);
  AM[u][v] = w; // directed graph
}

for (int k = 0; k < V; k++) // common error: remember that loop order is k->i->j
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);