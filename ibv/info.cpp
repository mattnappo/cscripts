#include <cstdio>
#include <cstdlib>
#include <inttypes.h>
#include <infiniband/verbs.h>

int main() {
    int num_devices;
    struct ibv_device **dev_list;

    dev_list = ibv_get_device_list(&num_devices);
    if (!dev_list) {
        fprintf(stderr, "error getting infiniband devices\n");
        exit(1);
    }

    printf("RDMA devices:\n");

    for (int i = 0; i < num_devices; i++) {
        // get device name
        const char* dev_name = ibv_get_device_name(dev_list[i]);
        printf("name: \t\t%s\n", dev_name);

        // get device GUID
        uint64_t dev_guid = ibv_get_device_guid(dev_list[i]);
        printf("GUID: \t\t0x%016" PRIx64 "\n", dev_guid);

        // other info
        printf("dev name: \t%s\n", dev_list[i]->dev_name);
        printf("dev path: \t%s\n", dev_list[i]->dev_path);
        printf("ibdev path: \t%s\n", dev_list[i]->ibdev_path);
        printf("\n");
    }

    ibv_free_device_list(dev_list); // cleanup

    return 0;
}

