#include <gtest/gtest.h>  
#include "queue.h"  


// Failing Test Cases 
TEST(QueueTest, FailingEnqueueTest) {
    Queue queue = queue_create(2);
    EXPECT_EQ(1, queue_enqueue(&queue, 1));
    EXPECT_EQ(1, queue_enqueue(&queue, 2));
    EXPECT_EQ(0, queue_enqueue(&queue, 3)); // Expected fail  
    EXPECT_EQ(0, queue_enqueue(&queue, 4)); // Expected fail 
}

TEST(QueueTest, FailingDequeueTest) {  
    Queue queue = queue_create(3);  
    int item;  
    queue_enqueue(&queue, 5);  
    queue_enqueue(&queue, 6);
    queue_dequeue(&queue, &item);  
    EXPECT_EQ(5, item); // Should pass  
    queue_dequeue(&queue, &item);
    EXPECT_EQ(6, item); // Should pass 
    EXPECT_EQ(0, queue_dequeue(&queue, &item)); // Expected fail 
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

// Test for IsEmpty functionality  
TEST(QueueTest, IsEmptyTest) {  
    Queue queue = queue_create(3);  
    EXPECT_EQ(1, queue_is_empty(&queue)); // Empty  
    queue_enqueue(&queue, 5);  
    EXPECT_EQ(0, queue_is_empty(&queue)); // Not empty  
    queue_dequeue(&queue, nullptr);  
    EXPECT_EQ(1, queue_is_empty(&queue)); // Empty again  
}  

// Test for Peek functionality  
TEST(QueueTest, PeekTest) {  
    Queue queue = queue_create(3);  
    int item;  

    // Empty queue
    EXPECT_EQ(0, queue_peek(&queue, nullptr)); 
    EXPECT_EQ(0, queue_peek(&queue, &item)); 

    queue_enqueue(&queue, 5);  
    queue_enqueue(&queue, 6);  

    EXPECT_EQ(1, queue_peek(&queue, &item));  
    EXPECT_EQ(5, item);  

    queue_dequeue(&queue, nullptr);  
    
    EXPECT_EQ(1, queue_peek(&queue, &item));
    EXPECT_EQ(6, item);  

    queue_dequeue(&queue, nullptr);  
    EXPECT_EQ(0, queue_peek(&queue, nullptr)); 
}

int main(int argc, char **argv) {  
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();
}