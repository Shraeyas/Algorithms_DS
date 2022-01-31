
package DepthFirstSearch;

import BreadthFirstSearch.vertex;
import java.util.List;
import java.util.Stack;

public class Dfs_ite 
{
    private Stack<Vertex> stk;
    
    public Dfs_ite()
    {
        this.stk = new Stack<>();
    }
    
    public void dfs(List<Vertex> vertexList)
    {
        for(Vertex v : vertexList)
        {
            if(!v.isVisited())
            {
                v.setVisited(true);
                dfs(v);
            }
        }
    }
    
    private void dfs(Vertex v)
    {
        this.stk.add(v);
        
        while(!stk.isEmpty())
        {
            Vertex cur = this.stk.pop();
            System.out.println(cur.name + " ");
            
            for(Vertex ver : cur.getNbr())
            {
                if(!ver.isVisited())
                {
                    ver.setVisited(true);
                    this.stk.push(ver);
                }
            }
        }
    }
}
