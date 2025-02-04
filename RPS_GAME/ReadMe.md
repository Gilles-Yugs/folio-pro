# RPS_Game Docker Setup  
  
This repository contains the necessary files to build and run the **Rock Paper Scissors** (RPS) game project inside a Docker container. This approach simplifies the setup and execution across different operating systems, such as Windows, Linux, and macOS.  

## Prerequisites  

Before proceeding, ensure you have the following installed on your machine:  
- **Docker**: Ensure Docker is installed and running on your system. You can download Docker from [docker.com](https://www.docker.com/).  

## Steps to Build and Run the Docker Container  

### 1. Clone the Repository  

Clone this repository to your local machine (if you haven't already):  

```bash  
git clone https://github.com/Gilles-Yugs/folio-pro.git  
cd folio-pro/RPS_GAME  
```  
  
## Build the Docker Image  

To build the Docker image from the provided Dockerfile, run the following command inside the repository directory:  

```  
docker build -t rps_game .  
```  

This command will:  
Install the necessary dependencies inside the container (e.g., cmake, git, doxygen, etc.).  
Set up the environment for building the project.    

## Run the Docker Container  

Once the image is built successfully, you can run the Docker container. This will execute the container interactively and remove it after execution:  

```  
docker run -it --rm rps_game  
```  

This will launch the container and place you inside its shell (root directory). From here, you can proceed to build the project and execute it.  

## Execute the RPS Game

After successfully building the project, you can run the RPS game executable:  

```  
cd ..  
./out/rps_executable  
```  

This will start the Rock Paper Scissors game in the terminal.  

## Execute the RPS Game  

```  
exit  
```  