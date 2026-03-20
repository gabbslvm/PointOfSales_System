# C++offee — Point of Sales System

A console-based Point of Sales (POS) system for a fictional coffee shop, built using the C++ programming language. Handles customer ordering, inventory management, discounts, VAT computation, and receipt printing — all within the terminal.

> **Course:** Computer Programming — School Project

---

## Features

- **Dual User Mode** — Separate flows for Employee and Customer
- **Employee Mode** — Password-protected inventory management (CRUD operations)
- **Customer Ordering** — Browse a menu of 12 items (coffees, pastries, and food) with live stock display
- **Senior / PWD Discount** — 20% discount applied automatically on request
- **VAT Computation** — 12% VAT calculated on the discounted total
- **Receipt Printing** — Formatted ASCII receipt with itemized order, discount, VAT, and final total
- **Payment Handling** — Accepts cash payment and computes change

---

## Menu

| Category | Items |
|----------|-------|
| Coffee & Drinks | Javascript (Javachip), C#appuccino, Cout Latte, C-trawberry Latte, Double Dark Roast, Compilepresso |
| Pastries & Food | JavaBeans Brownies, Blueberry Py, Peach Mango Py, Apple Py, Byte-sized Cookie, RAM-en Noodles |

---

## Tech Stack

| | |
|-|-|
| Language | C++ |
| Interface | Console / Terminal |
| Compiler | Any standard C++ compiler (g++, MSVC, etc.) |

---

## How to Run

### Prerequisites
- A C++ compiler (e.g., `g++` via MinGW or GCC)

### Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/gabbslvm/PointOfSales_System.git
   cd PointOfSales_System
   ```

2. **Compile the source file**
   ```bash
   g++ src/sys.cpp -o pos
   ```

3. **Run the program**
   ```bash
   ./pos
   ```

---

## Default Employee Password

```
1234
```

> ⚠️ After 3 failed attempts, the system returns to the main menu.

---

## Project Structure

```
PointOfSales_System/
├── src/
│   └── sys.cpp        # Main source file
└── reference/         # Reference files and earlier drafts
```

---

## License

For academic use only.
