# Bike-Share-System

A simple and efficient system for renting normal bikes and scooters.

Check the UML diagrams (see BikeShareUML.jpeg) to quickly understand the system.
## Features

- Rent and return normal bikes and scooters.  
- Track trips and calculate costs dynamically.  
- Handle maintenance tickets for bikes and scooters.  
- Support multiple payment methods (Cash, PayPal).  
- Designed to be extensible for future enhancements.  

## Project Goal

The main goal of this project was to practice proper software design:

- Writing reusable and generic code.  
- Applying core OOP concepts.  
- Structuring a complex system in a maintainable way.
- 
### Key Classes

- **User Hierarchy**: `User` (abstract) → `Customer`, `Admin`, `StationOperator`, `MaintenanceTechnician`
- **Bike Hierarchy**: `IBike` (interface) → `Scooter`, `NormalBike`
- **Station Management**: `Station`, `StationsManager`
- **Trip and Billing**: `Trip`, `Invoice`
- **Payment Services**: `IPaymentService` (interface)  → `CashPayment`, `PayPal`
- **Support Classes**: `CardInfo`, `MaintenanceTicket`, `UIManager`, `UserManager`

### Notes

- Each class is separated into its own header (`.h`) and implementation (`.cpp`) file.
- Modular design ensures scalability and maintainability.

## Try It Yourself

If you want to try the system, you can clone this repository and open it using Visual Studio.


```bash
git clone https://github.com/ZeyadGasser/Bike-Share-System.git
