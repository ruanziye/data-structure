package 图;
import java.util.*;

public class Graph {
    private int[][] matrix; // 邻接矩阵
    private LinkedList<Integer>[] list; // 邻接表
    private int vertexNum; // 顶点数

    // 构造函数，初始化图的顶点数
    public Graph(int vertexNum) {
        this.vertexNum = vertexNum;
    }

    // 创建邻接矩阵
    public void createMatrix() {
        matrix = new int[vertexNum][vertexNum];
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入邻接矩阵：");
        for (int i = 0; i < vertexNum; i++) {
            for (int j = 0; j < vertexNum; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
    }

    // 创建邻接表
    public void createList() {
        list = new LinkedList[vertexNum];
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入邻接表：");
        for (int i = 0; i < vertexNum; i++) {
            list[i] = new LinkedList<Integer>();
            int j = scanner.nextInt();
            while (j != -1) {
                list[i].add(j);
                j = scanner.nextInt();
            }
        }
    }

    // 深度优先遍历
    public void dfs(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");
        for (int i = 0; i < vertexNum; i++) {
            if (matrix[v][i] != 0 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

    // 广度优先遍历
    public void bfs(int v, boolean[] visited) {
        Queue<Integer> queue = new LinkedList<Integer>();
        visited[v] = true;
        queue.offer(v);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            System.out.print(u + " ");
            for (int i = 0; i < vertexNum; i++) {
                if (matrix[u][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    queue.offer(i);
                }
            }
        }
    }

    // 找第一个邻接点
    public int firstNeighbor(int v) {
        for (int i = 0; i < vertexNum; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return -1;
    }

    // 找下一个邻接点
    public int nextNeighbor(int v, int w) {
        for (int i = w + 1; i < vertexNum; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return -1;
    }

    // 应用
    public void application() {
        // TODO: 实现应用
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入顶点数：");
        int vertexNum = scanner.nextInt();
        Graph graph = new Graph(vertexNum);
        int n;
        do {
            System.out.println("\n****************图的基本操作及应用*****************");
            System.out.println("* 1  创建（邻接矩阵/邻接表）                      *");
            System.out.println("* 2  深度优先遍历                                 *");
            System.out.println("* 3  广度优先遍历                                 *");
            System.out.println("* 4  找第一个邻接点                               *");
            System.out.println("* 5  找下一个邻接点                               *");
            System.out.println("* 6  应用                                         *");
            System.out.println("* 7  退出                                         *");
            System.out.println("***************************************************");
            System.out.print("请选择：");
            n = scanner.nextInt();
            switch (n) {
                case 1:
                    System.out.println("---------创建（邻接矩阵/邻接表）-------");
                    System.out.print("请选择创建邻接矩阵（1）还是邻接表（2）：");
                    int choice = scanner.nextInt();
                    if (choice == 1) {
                        graph.createMatrix();
                    } else if (choice == 2) {
                        graph.createList();
                    } else {
                        System.out.println("输入错误！");
                    }
                    break;
                case 2:
                    System.out.println("---------深度优先遍历-------");
                    boolean[] visited1 = new boolean[vertexNum];
                    System.out.print("请输入起始顶点：");
                    int start1 = scanner.nextInt();
                    graph.dfs(start1, visited1);
                    break;
                case 3:
                    System.out.println("---------广度优先遍历-------");
                    boolean[] visited2 = new boolean[vertexNum];
                    System.out.print("请输入起始顶点：");
                    int start2 = scanner.nextInt();
                    graph.bfs(start2, visited2);
                    break;
                case 4:
                    System.out.println("---------找第一个邻接点-------");
                    System.out.print("请输入顶点：");
                    int v1 = scanner.nextInt();
                    int first = graph.firstNeighbor(v1);
                    if (first == -1) {
                        System.out.println("该顶点没有邻接点！");
                    } else {
                        System.out.println("第一个邻接点为：" + first);
                    }
                    break;
                case 5:
                    System.out.println("---------找下一个邻接点-------");
                    System.out.print("请输入顶点：");
                    int v2 = scanner.nextInt();
                    System.out.print("请输入当前邻接点：");
                    int w = scanner.nextInt();
                    int next = graph.nextNeighbor(v2, w);
                    if (next == -1) {
                        System.out.println("该顶点没有下一个邻接点！");
                    } else {
                        System.out.println("下一个邻接点为：" + next);
                    }
                    break;
                case 6:
                    System.out.println("---------应用-------");
                    graph.application();
                    break;
                case 7:
                    break;
                default:
                    System.out.println("ERROR!");
                    break;
            }
        } while (n != 7);
    }
}