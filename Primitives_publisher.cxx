
#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()

#include "Primitives.hpp"

void publisher_main(int domain_id, int sample_count)
{
    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant (domain_id);

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<PrimitiveStruct> topic (participant, "Example PrimitiveStruct");

    // Create a DataWriter with default Qos (Publisher created in-line)
    dds::pub::DataWriter<PrimitiveStruct> writer(dds::pub::Publisher(participant), topic);

	PrimitiveStruct sample;
	sample.theBool(true);
	sample.theChar('c');
	sample.theDouble(1234.567891012);
	sample.theFloat(0.5);
	sample.theLongLong(2147483648);
	sample.theLong(2147483647);
	sample.theOctet(10); 
	sample.ThePointer(NULL);
	sample.theShort(65535);
	sample.theUnsignedLong(9223372036854775807);
	sample.theUnsignedLongLong(922337203000000007);
	sample.theUnsignedShort(1203);
	sample.thWchar('W');
	sample.theLongDouble(1.1);

    for (int count = 0; count < sample_count || sample_count == 0; count++) {
        // Modify the data to be written here

        std::cout << "Writing PrimitiveStruct, count " << count << std::endl;
        writer.write(sample);

        rti::util::sleep(dds::core::Duration(4));
    }
}

int main(int argc, char *argv[])
{

    int domain_id = 0;
    int sample_count = 0; // infinite loop

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        publisher_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

