package ͼ;
import java.util.*;

public class Graph {
    private int[][] matrix; // �ڽӾ���
    private LinkedList<Integer>[] list; // �ڽӱ�
    private int vertexNum; // ������

    // ���캯������ʼ��ͼ�Ķ�����
    public Graph(int vertexNum) {
        this.vertexNum = vertexNum;
    }

    // �����ڽӾ���
    public void createMatrix() {
        matrix = new int[vertexNum][vertexNum];
        Scanner scanner = new Scanner(System.in);
        System.out.println("�������ڽӾ���");
        for (int i = 0; i < vertexNum; i++) {
            for (int j = 0; j < vertexNum; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
    }

    // �����ڽӱ�
    public void createList() {
        list = new LinkedList[vertexNum];
        Scanner scanner = new Scanner(System.in);
        System.out.println("�������ڽӱ�");
        for (int i = 0; i < vertexNum; i++) {
            list[i] = new LinkedList<Integer>();
            int j = scanner.nextInt();
            while (j != -1) {
                list[i].add(j);
                j = scanner.nextInt();
            }
        }
    }

    // ������ȱ���
    public void dfs(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");
        for (int i = 0; i < vertexNum; i++) {
            if (matrix[v][i] != 0 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

    // ������ȱ���
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

    // �ҵ�һ���ڽӵ�
    public int firstNeighbor(int v) {
        for (int i = 0; i < vertexNum; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return -1;
    }

    // ����һ���ڽӵ�
    public int nextNeighbor(int v, int w) {
        for (int i = w + 1; i < vertexNum; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return -1;
    }

    // Ӧ��
    public void application() {
        // TODO: ʵ��Ӧ��
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("�����붥������");
        int vertexNum = scanner.nextInt();
        Graph graph = new Graph(vertexNum);
        int n;
        do {
            System.out.println("\n****************ͼ�Ļ���������Ӧ��*****************");
            System.out.println("* 1  �������ڽӾ���/�ڽӱ�                      *");
            System.out.println("* 2  ������ȱ���                                 *");
            System.out.println("* 3  ������ȱ���                                 *");
            System.out.println("* 4  �ҵ�һ���ڽӵ�                               *");
            System.out.println("* 5  ����һ���ڽӵ�                               *");
            System.out.println("* 6  Ӧ��                                         *");
            System.out.println("* 7  �˳�                                         *");
            System.out.println("***************************************************");
            System.out.print("��ѡ��");
            n = scanner.nextInt();
            switch (n) {
                case 1:
                    System.out.println("---------�������ڽӾ���/�ڽӱ�-------");
                    System.out.print("��ѡ�񴴽��ڽӾ���1�������ڽӱ�2����");
                    int choice = scanner.nextInt();
                    if (choice == 1) {
                        graph.createMatrix();
                    } else if (choice == 2) {
                        graph.createList();
                    } else {
                        System.out.println("�������");
                    }
                    break;
                case 2:
                    System.out.println("---------������ȱ���-------");
                    boolean[] visited1 = new boolean[vertexNum];
                    System.out.print("��������ʼ���㣺");
                    int start1 = scanner.nextInt();
                    graph.dfs(start1, visited1);
                    break;
                case 3:
                    System.out.println("---------������ȱ���-------");
                    boolean[] visited2 = new boolean[vertexNum];
                    System.out.print("��������ʼ���㣺");
                    int start2 = scanner.nextInt();
                    graph.bfs(start2, visited2);
                    break;
                case 4:
                    System.out.println("---------�ҵ�һ���ڽӵ�-------");
                    System.out.print("�����붥�㣺");
                    int v1 = scanner.nextInt();
                    int first = graph.firstNeighbor(v1);
                    if (first == -1) {
                        System.out.println("�ö���û���ڽӵ㣡");
                    } else {
                        System.out.println("��һ���ڽӵ�Ϊ��" + first);
                    }
                    break;
                case 5:
                    System.out.println("---------����һ���ڽӵ�-------");
                    System.out.print("�����붥�㣺");
                    int v2 = scanner.nextInt();
                    System.out.print("�����뵱ǰ�ڽӵ㣺");
                    int w = scanner.nextInt();
                    int next = graph.nextNeighbor(v2, w);
                    if (next == -1) {
                        System.out.println("�ö���û����һ���ڽӵ㣡");
                    } else {
                        System.out.println("��һ���ڽӵ�Ϊ��" + next);
                    }
                    break;
                case 6:
                    System.out.println("---------Ӧ��-------");
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