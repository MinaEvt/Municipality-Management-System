#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <string>
#include <iostream>

// Enum for request status
enum class RequestStatus { 
    Pending, 
    InProgress, 
    Completed, 
    Rejected 
};

class ServiceRequest {
private:
    int requestId;
    int citizenId;
    std::string requestType;
    std::string description;
    RequestStatus status;

public:
    ServiceRequest(int requestId = 0, int citizenId = 0, const std::string& requestType = "",
                   const std::string& description = "", RequestStatus status = RequestStatus::Pending);

    // Getters
    int getRequestId() const;
    int getCitizenId() const;
    std::string getRequestType() const;
    std::string getDescription() const;
    RequestStatus getStatus() const;
    std::string getStatusString() const;

    // Setters
    void setRequestId(int requestId);
    void setCitizenId(int citizenId);
    void setRequestType(const std::string& requestType);
    void setDescription(const std::string& description);
    void setStatus(RequestStatus status);

    // Methods
    void display() const;
    std::string toString() const;

    // Operator overloading
    friend std::ostream& operator<<(std::ostream& os, const ServiceRequest& request);
    bool operator==(const ServiceRequest& other) const;
};

#endif // SERVICEREQUEST_H