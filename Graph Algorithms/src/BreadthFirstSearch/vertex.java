/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BreadthFirstSearch;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Shraeyas
 */
public class vertex 
{
    private int data;
    public boolean visited;
    private List<vertex>nbr;
    
    public vertex (int data)
    {
        this.data = data;
        this.nbr = new ArrayList<>();
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public boolean isVisited() {
        return visited;
    }

    public void setVisited(boolean visited) 
    {    
        this.visited = visited;
    }

    public List<vertex> getNbr() {
        return nbr;
    }

    public void setNbr(List<vertex> nbr) {
        this.nbr = nbr;
    }

    public void addnbr(vertex vt)
    {
        this.nbr.add(vt);
    }
    
    @Override
    public String toString() 
    {
        return "" + this.data;
    }
    
    
}
