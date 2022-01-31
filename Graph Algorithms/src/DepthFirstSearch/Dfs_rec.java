
package DepthFirstSearch;

import java.util.List;

public class Dfs_rec 
{
    public void dfs(List <Vertex> list)
    {
        for(Vertex v : list)
        {
            if(!v.isVisited())
            {
                v.setVisited(true);
                System.out.println(v.name + " ");
                dfs(v);
            }
        }
    }
    
    private void dfs(Vertex v)
    {
        for(Vertex ver : v.getNbr())
        {
            if(!ver.isVisited())
            {
                System.out.println(ver.name + " ");
                ver.setVisited(true);
                dfs(ver);
            }
        }
    }
}
