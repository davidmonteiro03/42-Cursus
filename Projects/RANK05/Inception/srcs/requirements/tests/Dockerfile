# Use a base image with Debian Bullseye
FROM debian:bullseye-slim

WORKDIR /app

# Copy the requirements file and install dependencies
COPY requirements/tests.txt /app/requirements.txt
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        python3 \
        python3-pip && \
    pip3 install --no-cache-dir -r requirements.txt && \
    apt-get remove -y python3-pip && \
    apt-get autoremove -y && \
    rm -rf /var/lib/apt/lists/*

# Copy the source code into the container
COPY srcs /app/srcs

# Set the entry point for running tests
CMD ["pytest", "srcs"]
