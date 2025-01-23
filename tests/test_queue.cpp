#include <gtest/gtest.h>  
#include "queue.h"  


class QueueTest : public ::testing::Test {  
protected:  
    Queue queue;  

    void SetUp() override {  
        queue = queue_create(3);  
    }  

    void TearDown() override {  
        queue_free(&queue);  
    }  
};  

// Failing Test Cases 
TEST_F(QueueTest, FailingEnqueueTest) {
    EXPECT_EQ(1, queue_enqueue(&queue, 1));
    EXPECT_EQ(1, queue_enqueue(&queue, 2));
    EXPECT_EQ(1, queue_enqueue(&queue, 3)); 
    EXPECT_EQ(0, queue_enqueue(&queue, 4)); // Expected fail 
}

TEST_F(QueueTest, FailingDequeueTest) {  
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
TEST_F(QueueTest, EnqueueTest) {  
    EXPECT_EQ(1, queue_enqueue(&queue, 5));  
    EXPECT_EQ(1, queue_enqueue(&queue, 6));  
    EXPECT_EQ(1, queue_enqueue(&queue, 7));
    EXPECT_EQ(0, queue_enqueue(&queue, 8)); // Expected fail
}  

// Test for Dequeue functionality  
TEST_F(QueueTest, DequeueTest) {  
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
TEST_F(QueueTest, IsEmptyTest) {  
    // Queue queue = queue_create(3);  
    EXPECT_EQ(1, queue_is_empty(&queue)); // Empty  
    queue_enqueue(&queue, 5);  
    EXPECT_EQ(0, queue_is_empty(&queue)); // Not empty  
    queue_dequeue(&queue, nullptr);  
    EXPECT_EQ(1, queue_is_empty(&queue)); // Empty again  
}  

// Test for Peek functionality  
TEST_F(QueueTest, PeekTest) {  
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