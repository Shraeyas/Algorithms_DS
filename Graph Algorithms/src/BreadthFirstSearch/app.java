package BreadthFirstSearch;

public class app 
{
    public static void main(String args [])
    {
        bfs BFS = new bfs();

        vertex vertex1 = new vertex(1);
        vertex vertex2 = new vertex(2);
        vertex vertex3 = new vertex(3);
        vertex vertex4 = new vertex(4);
        vertex vertex5 = new vertex(5);

        vertex1.addnbr(vertex2);
        vertex1.addnbr(vertex4);
        vertex4.addnbr(vertex5);
        vertex2.addnbr(vertex3);
        
        BFS.bfs(vertex1);
    }
}