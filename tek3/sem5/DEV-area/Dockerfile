# Use the official Python image as a base image
FROM python:3.10-slim

# Set the working directory
WORKDIR /app

# Copy the requirements file and install dependencies
COPY requirements.txt .

# Install dependencies globally
RUN pip install --upgrade pip && \
    pip install -r requirements.txt

# Copy the rest of the Django application
COPY nell_backend/ .

# Expose port 8000
EXPOSE 8000

# Set the entrypoint to run the Django server
CMD ["python3", "manage.py", "runserver", "0.0.0.0:8000"]