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

---
## 🎥 Demo Video Link
