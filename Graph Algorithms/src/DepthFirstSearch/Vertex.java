package DepthFirstSearch;

import BreadthFirstSearch.vertex;
import java.util.ArrayList;
import java.util.List;

public class Vertex 
{
    public String name;
    private boolean visited;
    private List<Vertex> nbr;
    
    public Vertex(String name)
    {
        this.name = name;
        this.nbr = new ArrayList<>();
        
    }

    public String getName() 
    {
        return name;
    }

    public void setName(String name) 
    {
        this.name = name;
    }

    public boolean isVisited() 
    {
        return visited;
    }

    public void setVisited(boolean visited) 
    {
        this.visited = visited;
    }

    public List<Vertex> getNbr() 
    {
        return nbr;
    }

    public void setNbr(List<Vertex> nbr) 
    {
        this.nbr = nbr;
    }
    
    public void addnbr(Vertex vertex)
    {
        this.nbr.add(vertex);
    }

}
