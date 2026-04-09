README.md
----

## 🛒 Project Title

**Online Marketplace Graph System (C Language)**

---

## 👨‍💻 Team Members

Member 1: K.V.S.Kishore

Member 2: M.Mineesh

---

## ❓ Problem Statement

In an online marketplace, products are often connected through recommendations (e.g., “Customers also bought”).
The goal of this project is to design a system that:

Stores products efficiently
Allows CRUD operations (Create, Read, Update, Delete)
Maintains product-to-product recommendations
Displays relationships between products

---
## 🧠 Data Structure Used

This project uses a Graph Data Structure implemented using Adjacency List.

**🔹 Components:**

        Nodes (Vertices): Products

        Edges: Recommendations between products

**🔹 Implementation:**

        Linked List → Stores all products

        Adjacency List → Stores recommendations for each product

        Product → Linked List of Products
                → Each product has its own Edge list (recommendations)

---

## ⚙ Algorithm Explanation

**1. Add Product**

        Input product ID and name

        Check if ID already exists

        Insert new node at beginning of linked list


**2. Delete Product**

        Find product node

        Remove all edges pointing to it

        Delete its adjacency list

        Remove node from linked list


**3. Update Product**

        Search by ID

        Replace product name


**4. Search Product**

        Traverse linked list

        Match ID


**5. Display Products**

        Traverse all nodes

        Print product details

        Print adjacency list (recommendations)


**6. Add Recommendation**

        Find source and destination product

        Create edge

        Insert into adjacency list

---

## 💻 Compilation Instructions

**🔹 Step 1: Save File**

        Save your code as:

                marketplace.c


**🔹 Step 2: Compile**

        Use GCC compiler:

                gcc marketplace.c -o marketplace


**🔹 Step 3: Run**
    
        ./marketplace

        (For Windows:)

                marketplace.exe

---

## 📌 Sample Output

1. main menu
   <img width="365" height="223" alt="11" src="https://github.com/user-attachments/assets/25f0fc84-9113-4725-ae8e-46d30d11ecba" />


2.Add Node

 <img width="300" height="126" alt="12" src="https://github.com/user-attachments/assets/e799039c-b511-4125-a892-4a2a1485b169" />

 <img width="297" height="116" alt="19" src="https://github.com/user-attachments/assets/3962f401-8549-4f53-85d1-7e46dae1df0d" />

 

3.delete node

<img width="331" height="96" alt="13" src="https://github.com/user-attachments/assets/9ce9bf64-83a0-49e3-b7de-90dcd861157f" />


4.update node

<img width="327" height="123" alt="14" src="https://github.com/user-attachments/assets/563f89d2-e500-47d9-833d-319b576a950b" />



5.search 

<img width="343" height="102" alt="15" src="https://github.com/user-attachments/assets/a8f4a284-7301-4a5f-af3a-e619338424a3" />


6.display

<img width="263" height="137" alt="16" src="https://github.com/user-attachments/assets/15af93c5-8088-4e5c-ad0c-6acefb4ec0fd" />


7. Add Recommendation

 <img width="322" height="112" alt="17" src="https://github.com/user-attachments/assets/40271668-4ca9-4251-bc14-48f111b43ad6" />


8.Exit

<img width="520" height="52" alt="18" src="https://github.com/user-attachments/assets/b3745d39-0307-4dd6-b96a-1354d0ff8415" />


---

