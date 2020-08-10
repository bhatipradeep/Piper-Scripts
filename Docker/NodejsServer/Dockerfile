#file to create the docker image

From node:12

#create directory
WORKDIR /usr/src/app

#copying package.json and package-lock.json to the docker image when construted
COPY package*.json ./

#run this command when the docker image as container
RUN npm install

#bundle app source
COPY . .

#To use 8080 port in express server use it to map to docker daemon
EXPOSE 8080

#run this in cli to start the server
CMD [ "node", "server.js" ]
