#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <queue>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <vector>
#include <cstdarg>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
const int INFTY = numeric_limits<int>::max();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int BUFF_SIZE = 1024 * 256;
char g_rbuffer[BUFF_SIZE], *g_rpos = g_rbuffer, *g_rend = g_rbuffer;
#define READ_HELPER(fnAccum, fnEnd, fnCheck) while (true) { for (; g_rpos != g_rend && (fnCheck); ++g_rpos) fnAccum;\
if (g_rpos != g_rend) fnEnd; g_rend = g_rbuffer + read(0, g_rbuffer, BUFF_SIZE), g_rpos = g_rbuffer; }
template<typename R> void readNumber(R &rtn) {
rtn = 0;
READ_HELPER(;, break, *g_rpos < '0' || *g_rpos > '9'); READ_HELPER(rtn = rtn * 10 + *g_rpos - '0', return, *g_rpos >= '0' && *g_rpos <= '9');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char g_wbuffer[BUFF_SIZE];
char *g_wpos = g_wbuffer, *g_wend = g_wbuffer + BUFF_SIZE;
inline void flushWBuffer() { write(1, g_wbuffer, g_wpos - g_wbuffer); g_wpos = g_wbuffer;}
inline void writeChar(char ch) { *(g_wpos++) = ch; if (g_wpos == g_wend) flushWBuffer(); }
void writeBuffer(char *start, char *end) { for (; start != end; start += 1) writeChar(*start); }
template<typename I> void writeNumber(I n) {
static char tmpBuffer[100];
char *cur = tmpBuffer, *start = tmpBuffer;
if (n == 0) { writeChar('0'); return; }
if (n < 0) *(cur++) = '-', n *= -1, start += 1;
while (n) *(cur++) = n % 10 + '0', n /= 10;
reverse(start, cur); writeBuffer(tmpBuffer, cur);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int MAX_VERTECES = 1000 + 1;
const int MAX_EDGES = (MAX_VERTECES * (MAX_VERTECES - 1)) + 1;
int nNodes, nEdges;
struct Edge {
int v1, v2, w;
bool operator<(const Edge &rhs) const { return !(w < rhs.w); }
};
struct EdgeSorter {
bool operator ()(const Edge &lhs, const Edge &rhs) {
return lhs.w > rhs.w;
}
};
Edge aEdges[MAX_EDGES];
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DSU {
DSU *parent;
int rank;
DSU(): parent(this), rank(0) {;}
};
DSU* findRoot(DSU *node) {
if (node->parent != node) node->parent = findRoot(node->parent);
return node->parent;
}
void setUnion(DSU *lhs, DSU *rhs) {
lhs = findRoot(lhs), rhs = findRoot(rhs);
if (lhs == rhs) return;
if (lhs->rank == rhs->rank) rhs->rank += 1;
if (lhs->rank < rhs->rank) lhs->parent = rhs;
else rhs->parent = lhs;
}
DSU aVerteces[MAX_VERTECES];
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int aResult[MAX_VERTECES][MAX_VERTECES] = {{0}};
bool abVisited[MAX_VERTECES];
list< pair<int, int> > mstEdges[MAX_VERTECES]; // w, v
void dfs(int from, int to, int minInPath = INFTY) {
abVisited[to] = true;
each(mstEdges[to], it) {
if (abVisited[it->second]) continue;
//cout << "(" << from << ") " << to << " -> " << it->second << " w = " << it->first << endl;
aResult[from][it->second] = min(minInPath, it->first);
dfs(from, it->second, aResult[from][it->second]);
}
}
int main(int argc, char **argv) {
int i, j;
readNumber(nNodes), readNumber(nEdges);
for (i = 0; i < nEdges; i += 1) {
readNumber(aEdges[i].v1), readNumber(aEdges[i].v2), readNumber(aEdges[i].w);
}
EdgeSorter sorter;
sort(aEdges, aEdges + nEdges, sorter);
for (i = 0; i < nEdges; i += 1) {
if (findRoot(&aVerteces[aEdges[i].v1]) != findRoot(&aVerteces[aEdges[i].v2])) {
setUnion(&aVerteces[aEdges[i].v1], &aVerteces[aEdges[i].v2]);
mstEdges[aEdges[i].v1].push_back(make_pair(aEdges[i].w, aEdges[i].v2));
mstEdges[aEdges[i].v2].push_back(make_pair(aEdges[i].w, aEdges[i].v1));
}
}
for (i = 0; i < nNodes; i += 1) {
fill_n(abVisited, nNodes, false);
dfs(i, i);
}
for (i = 0; i < nNodes; i += 1) {
if (i == 0) writeChar('0');
else writeNumber(i > 0 ? aResult[0][i] : aResult[i][0]);
for (j = 1; j < nNodes; j += 1) {
writeChar(' ');
if (i == j) writeChar('0');
else writeNumber(i > j ? aResult[j][i] : aResult[i][j]);
}
writeChar(' ');
writeChar('\n');
}
flushWBuffer();
return 0;
}