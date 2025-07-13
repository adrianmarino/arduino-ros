#pragma once
#include "RosMessage.h"
#include "MicroRosPublisher.h"


/**
 * StringPublisher class for publishing string messages using micro-ROS.
 *
 * This class provides methods to create a publisher and publish string messages
 * using the micro-ROS framework.
 */
class StringPublisher {
public:
    /**
     * Constructor for StringPublisher.
     * @param publisher Pointer to the MicroRosPublisher object.
     */
    StringPublisher(MicroRosPublisher* publisher) : publisher(publisher) {
        // Asignar memoria e inicializar el mensaje String
        msg = std_msgs__msg__String__create();
        if (msg) {
            // Puedes pre-asignar una capacidad si conoces un tamaño máximo aproximado
            // o dejar que se reasigne dinámicamente con __assign.
            // Por ejemplo, para pre-asignar para 50 caracteres:
            // rosidl_runtime_c__String__init(&msg->data);
            // if (!rosidl_runtime_c__String__assignn(&msg->data, "", 0)) {
            //    // Manejar error de asignación si es necesario
            // }
            // O simplemente inicializarlo vacío:
            rosidl_runtime_c__String__init(&msg->data);
        } else {
            // Manejar error de creación del mensaje si es necesario
        }
    }

    /**
     * Destructor for StringPublisher.
     * Libera la memoria del mensaje.
     */
    ~StringPublisher() {
        if (msg) {
            std_msgs__msg__String__destroy(msg);
            msg = nullptr;
        }
    }

    /**
     * Publish the string message.
     * @param data_str Pointer to the C-style string (char array) to be published.
     */
    void publish(const char *data_str) {
        if (publisher && msg) {
            if (rosidl_runtime_c__String__assign(&msg->data, data_str)) {
                publisher->publish(msg);
            } else {
                // Manejar error de asignación de string si es necesario
                // Por ejemplo, imprimir un error por Serial
            }
        }
    }

    /**
     * Publish the string message.
     * @param data_str Arduino String object to be published.
     */
    void publish(const String &data_str) {
        publish(data_str.c_str());
    }

private:
    MicroRosPublisher *publisher;
    std_msgs__msg__String *msg;
};
