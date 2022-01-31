package DepthFirstSearch;

import BreadthFirstSearch.vertex;
import java.util.ArrayList;
import java.util.List;

public class Driver 
{
    public static void main(String args[])
    {
        Vertex v1 = new Vertex("1");
        Vertex v2 = new Vertex("2");
        Vertex v3 = new Vertex("3");
        Vertex v4 = new Vertex("4");
        Vertex v5 = new Vertex("5");
        
        v1.addnbr(v2);
        v1.addnbr(v3);
        v3.addnbr(v4);
        v4.addnbr(v5);
        
        List <Vertex> pg = new ArrayList<>();
        
        pg.add(v1);
        pg.add(v2);
        pg.add(v3);
        pg.add(v4);
        pg.add(v5);
        
        System.out.println("DFS Iterative ");
        Dfs_ite p_g = new Dfs_ite();
        p_g.dfs(pg);
        
        
        v1.setVisited(false);
        v2.setVisited(false);
        v3.setVisited(false);
        v4.setVisited(false);
        v5.setVisited(false);
        
        System.out.println("DFS Recursive ");
        Dfs_rec prac = new Dfs_rec();
        prac.dfs(pg);
    }
}
