package BreadthFirstSearch;

import java.util.LinkedList;
import java.util.Queue;

public class bfs 
{
    public void bfs(vertex root)
    {
        Queue<vertex>q = new LinkedList<>();
        
        q.add(root);
        root.setVisited(true);
        
        while(!q.isEmpty())
        {
            vertex cur = q.remove();
            System.out.println(cur + " ");
            
            for(vertex v : cur.getNbr())
            {
                if(!v.isVisited())
                {
                    v.setVisited(true);
                    q.add(v);
                }
            }
        }
    }
    
}
