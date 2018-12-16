#define MAX_V 100 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
int V, k, vertex, weight;
int res[MAX_V][MAX_V], mf, f, s, t;                     // global variables
vector<vii> AL;              // res and AdjList contain the same flow graph
vi p;
void augment(int v, int minEdge) {  // traverse BFS spanning tree from s->t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global var f
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
                         res[p[v]][v] -= f; res[v][p[v]] += f; } }
int main() {
  scanf("%d %d %d", &V, &s, &t);
  memset(res, 0, sizeof res);
  AL.assign(V, vii());
  for (int u = 0; u < V; u++) {
    int k; scanf("%d", &k);
    while (k--) {
      int v, w; scanf("%d %d", &v, &w);
      res[u][v] = w;
      AL[u].emplace_back(v, 1);                      // to record structure
      AL[v].emplace_back(u, 1);              // do not forget the back edge
    }
  }
  mf = 0;                                         // mf stands for max_flow
  while (1) {                        // an O(VE^2) Edmonds Karp's algorithm
    f = 0;
    // run BFS, compare with the original BFS shown in Section 4.2.2
    bitset<MAX_V> vis; vis[s] = true;       // we change vi dist to bitset!
    queue<int> q; q.push(s);
    p.assign(MAX_V, -1);      // record the BFS spanning tree, from s to t!
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break; // immediately stop BFS if we already reach sink t
      for (auto v : AL[u])               // use AL for neighbor enumeration
        if (res[u][v.first] > 0 && !vis[v.first])
          vis[v.first] = true, q.push(v.first), p[v.first] = u;
    }
    augment(t, INF);   // find the min edge weight `f' in this path, if any
    if (f == 0) break; // we cannot send any more flow (`f' = 0), terminate
    mf += f; }          // we can still send a flow, increase the max flow!
  printf("%d\n", mf);                         // this is the max flow value
  return 0;
}
