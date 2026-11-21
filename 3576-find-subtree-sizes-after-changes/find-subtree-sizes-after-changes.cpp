class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Build the original tree
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        // Store the new parent of each node
        vector<int> newParent = parent;

        // Last ancestor with each character
        int last[26];
        fill(last, last + 26, -1);

        // Iterative DFS to avoid stack overflow
        // {node, isExit, previousLast}
        stack<array<int, 3>> st;

        st.push({0, 0, -1});

        while (!st.empty()) {
            auto [node, isExit, previousLast] = st.top();
            st.pop();

            int c = s[node] - 'a';

            if (isExit) {
                // Restore previous ancestor character
                last[c] = previousLast;
                continue;
            }

            int previous = last[c];

            // Find closest matching ancestor
            if (previous != -1) {
                newParent[node] = previous;
            }

            // Current node becomes the latest ancestor
            last[c] = node;

            // Restore the previous value after children finish
            st.push({node, 1, previous});

            // Visit original children
            for (int child : children[node]) {
                st.push({child, 0, -1});
            }
        }

        // Build the final tree
        vector<vector<int>> finalTree(n);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        // Get traversal order of final tree
        vector<int> order;
        stack<int> nodes;

        nodes.push(0);

        while (!nodes.empty()) {
            int node = nodes.top();
            nodes.pop();

            order.push_back(node);

            for (int child : finalTree[node]) {
                nodes.push(child);
            }
        }

        // Calculate subtree sizes
        vector<int> answer(n, 1);

        // Reverse order: children processed before parents
        for (int i = n - 1; i > 0; i--) {
            int node = order[i];

            answer[newParent[node]] += answer[node];
        }

        return answer;
    }
};