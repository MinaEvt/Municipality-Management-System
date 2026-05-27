#include "ServiceRequest.h"

// Constructor initializes member variables with default values
ServiceRequest::ServiceRequest(int requestId, int citizenId, const std::string& requestType,
                               const std::string& description, RequestStatus status)
    : requestId(requestId), citizenId(citizenId), requestType(requestType),
      description(description), status(status) {}


// Getters
int ServiceRequest::getRequestId() const {
    return requestId;
}
int ServiceRequest::getCitizenId() const {
    return citizenId;
}
std::string ServiceRequest::getRequestType() const {
    return requestType;
}
std::string ServiceRequest::getDescription() const {
    return description;
}
RequestStatus ServiceRequest::getStatus() const {
    return status;
}


// Setters
void ServiceRequest::setRequestId(int requestId) {
    this->requestId = requestId;
}
void ServiceRequest::setCitizenId(int citizenId) {
    this->citizenId = citizenId;
}
void ServiceRequest::setRequestType(const std::string& requestType) {
    this->requestType = requestType;
}
void ServiceRequest::setDescription(const std::string& description) {
    this->description = description;
}
void ServiceRequest::setStatus(RequestStatus status) {
    this->status = status;
}

// Method to convert status enum to string for display
std::string ServiceRequest::getStatusString() const {
    switch (status) {
        case RequestStatus::Pending:
            return "Pending";
        case RequestStatus::InProgress:
            return "In Progress";
        case RequestStatus::Completed:
            return "Completed";
        case RequestStatus::Rejected:
            return "Rejected";
        default:
            return "Unknown";
    }
}

// Method to display service request details
void ServiceRequest::display() const {}

// Operator overloading for output stream
std::ostream& operator<<(std::ostream& os, const ServiceRequest& request) {
    os << "Service Request: " << request.getRequestId() << ", Citizen ID: " << request.getCitizenId()
       << ", Type: " << request.getRequestType() << ", Description: " << request.getDescription()
       << ", Status: " << request.getStatusString();
    return os;
}

// Equality operator compares requestId
bool ServiceRequest::operator==(const ServiceRequest& other) const {
    return requestId == other.requestId;
}