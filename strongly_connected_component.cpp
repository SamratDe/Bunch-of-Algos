//  Strong Connectivity applies only to directed graphs. 
//  A directed graph is strongly connected if there is a directed path from any vertex 
//  to every other vertex.

//  Kosaraju's Linear time algorithm - Find Strongly Connected Components
//  Complexity: O(V + E)

//  STEPS:
//	create empty stack, do dfs(like topo sort)
//	reverse the direction of all arcs
//	pop vertex from the stack and do dfs from that popped vertex on the reverse graph

// 	FIRST DFS:
//	if we do a DFS of graph and store vertices according to their finish times, we make sure
//	that the finish time of a vertex that connects to other SCCs, will always be greater
//	than finish time of vertices in the other SCC

//	REVERSE THE GRAPH

// 	SECOND DFS:
//	In the reversed graph, the edges that connect two components are reversed.
//	So the sink becomes source. So if we do a DFS of the reversed graph using sequence of vertices
//	in stack, we process vertices from sink to source (in reversed graph). 
//	That is what we wanted to achieve and that is all needed to print SCCs one by one.
