import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Edge implements Comparable<Edge> {
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight){
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge other){
        return Integer.compare(this.weight, other.weight);
    }
}

class DSU{
    int[] parent;
    int[] rank;

    DSU(int n){
        parent = new int[n];
        rank = new int[n];
    
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    boolean union(int x , int y){
        int rx = find(x);
        int ry = find(y);

        if(rx == ry){
            return false;
        }

        if(rank[rx] < rank[ry]) parent[rx] = ry;
        else if(rank[rx] > rank[ry]) parent[ry] = rx;
        else{
            parent[ry] = rx;
            rank[rx]++;
        }
        return true;
    }

    boolean sameSet(int x, int y){
        return find(x) == find(y);
    }
}


public class kruskals {
    public static boolean Cycle(int n, List<Edge> edges){
        Collections.sort(edges);
        DSU dsu = new DSU(n);


        for(Edge e : edges){
            if(!dsu.union(e.src, e.dest)){
                return true;
            }
        }
        return false;
    }


    public static void main(String[] args){
        int n = 4;
        List<Edge> edges = new ArrayList<>();

        edges.add(new Edge(0, 1 , 10));
        edges.add(new Edge(1, 2 , 15));
        edges.add(new Edge(2, 3 , 5));
        edges.add(new Edge(3, 1 , 7));

        if(Cycle(n, edges)){
            System.out.println("Cycle Detected");
        }
        else{
            System.out.println("No Cycle");
        }
    }
}
