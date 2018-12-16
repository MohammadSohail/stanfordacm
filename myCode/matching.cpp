vi match, vis;                                          // global variables
vector<vi> AL;
int Aug(int L) {      // return 1 if there exists an augmenting path from L
  if (vis[L]) return 0;                               // return 0 otherwise
  vis[L] = 1;
  for (auto &R : AL[L])
    if (match[R] == -1 || Aug(match[R])) {
      match[R] = L;
      return 1;                                         // found 1 matching
    }
  return 0;                                                  // no matching
}
bool isprime(int v) {
  int primes[10] = {2,3,5,7,11,13,17,19,23,29};
  for (int i = 0; i < 10; i++)
    if (primes[i] == v)
      return true;
  return false;
}
int main() {
  int V = 5, Vleft = 3;                               // we ignore vertex 0
  AL.assign(V, vi());
  AL[1].push_back(3); AL[1].push_back(4);
  AL[2].push_back(3);
  // build unweighted bipartite graph with directed edge left->right set
  unordered_set<int> freeV;
  for (int L = 0; L < Vleft; L++)
    freeV.insert(L);  // assume all vertices on left set are free initially
  match.assign(V, -1);    // V is the number of vertices in bipartite graph
  int MCBM = 0;
  // Greedy pre-processing for trivial Augmenting Paths
  // try commenting versus un-commenting this for-loop
  for (int L = 0; L < Vleft; L++) {                               // O(V^2)
    vi candidates;
    for (auto &R : AL[L])
      if (match[R] == -1)
        candidates.push_back(R);
    if (candidates.size() > 0) {
      MCBM++;
      freeV.erase(L);              // L is matched, no longer a free vertex
      int a = rand()%candidates.size();   // randomize this greedy matching
      match[candidates[a]] = L;
    }
  }
  for (auto &f : freeV) {      // for each of the k remaining free vertices
    vis.assign(Vleft, 0);                    // reset before each recursion
    MCBM += Aug(f);        // once f is matched, f remains matched till end
  }
  printf("Found %d matchings\n", MCBM);
  return 0;
}
