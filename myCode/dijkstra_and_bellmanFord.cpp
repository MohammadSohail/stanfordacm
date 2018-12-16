typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1e9
int main() {
    int V, E, s; scanf("%d %d %d", &V, &E, &s);
    vector<vii> AL(V, vii());      // assign blank vectors of ii-s to AL
    for (int i = 0; i < E; i++) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    AL[u].emplace_back(v, w);                        // directed graph
    }
    // Dijkstra routine
    vi dist(V, INF); dist[s] = 0;               // INF = 1B to avoid overflow
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push({0, s});
                        // to sort the^ pairs by increasing distance from s
    while (!pq.empty()) {                                        // main loop
    int d, u; tie(d, u) = pq.top(); pq.pop();   // get shortest unvisited u
    if (d > dist[u]) continue;            // this is a very important check
    for (auto &v : AL[u]) {                    // all outgoing edges from u
      if (dist[u]+v.second < dist[v.first]) {
        dist[v.first] = dist[u]+v.second;                // relax operation
        pq.push({dist[v.first], v.first});
    } } }     // this variant can cause duplicate items in the priority queue
    for (int i = 0; i < V; i++) // index + 1 for final answer
    printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

    // Bellman Ford routine
    vi dist(V, INF); dist[s] = 0;
    for (int i = 0; i < V-1; i++) // relax all E edges V-1 times, total O(VE)
      for (int u = 0; u < V; u++)                   // these two loops = O(E)
        if (dist[u] != INF)  // important: do not propagate if dist[u] == INF
          for (auto &v : AL[u])   // we can record SP spanning here if needed
            dist[v.first] = min(dist[v.first], dist[u]+v.second);    // relax

    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++) if (dist[u] != INF) // one more pass to check
      for (auto &v : AL[u])
        if (dist[v.first] > dist[u]+v.second)            // should be false
          hasNegativeCycle = true;  // if true, then negative cycle exists!
    printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

    if (!hasNegativeCycle)
      for (int i = 0; i < V; i++)
        printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
  return 0;
}
