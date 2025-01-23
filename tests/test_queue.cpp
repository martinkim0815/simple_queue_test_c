#include <gtest/gtest.h>  
#include "queue.h"  


// Failing Test Cases 
TEST(QueueTest, FailingEnqueueTest) {
    Queue queue = queue_create(2);
    EXPECT_EQ(1, queue_enqueue(&queue, 1));
    EXPECT_EQ(1, queue_enqueue(&queue, 2));
    EXPECT_EQ(1, queue_enqueue(&queue, 3)); // Should fail  
    EXPECT_EQ(1, queue_enqueue(&queue, 4)); // Should fail  
}

TEST(QueueTest, FailingDequeueTest) {  
    Queue queue = queue_create(3);  
    int item;  
    queue_enqueue(&queue, 1);  
    queue_enqueue(&queue, 2);
    queue_dequeue(&queue, &item);  
    EXPECT_EQ(1, item); // Should pass  
    EXPECT_EQ(5, queue_dequeue(&queue, &item)); // Should fail   
} 

// Success Test Cases
// Test for Enqueue functionality  
TEST(QueueTest, EnqueueTest) {  
    Queue queue = queue_create(3);  
    EXPECT_EQ(1, queue_enqueue(&queue, 5));  
    EXPECT_EQ(1, queue_enqueue(&queue, 6));  
    EXPECT_EQ(1, queue_enqueue(&queue, 7));
    EXPECT_EQ(0, queue_enqueue(&queue, 8)); // Expected fail
}  

// Test for Dequeue functionality  
TEST(QueueTest, DequeueTest) {  
    Queue queue = queue_create(3);  
    int item;  
    queue_enqueue(&queue, 5);  
    queue_enqueue(&queue, 6);  
    EXPECT_EQ(1, queue_dequeue(&queue, &item));  
    EXPECT_EQ(5, item);  
    EXPECT_EQ(1, queue_dequeue(&queue, &item));  
    EXPECT_EQ(6, item);  
    EXPECT_EQ(0, queue_dequeue(&queue, &item)); // Expected fail
}  

int main(int argc, char **argv) {  
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();
}