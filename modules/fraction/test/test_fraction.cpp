// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include "include/fraction.h"

class FractionTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(FractionTest, Can_Create_Fraction_With_Default_constructor) {
    // Arrange
    // Act
    Fraction f;

    // Assert
    EXPECT_EQ(1, f.getNominator());
    EXPECT_EQ(1, f.getDenominator());
}

TEST_F(FractionTest, Can_Create_Fraction_With_One_Parameter_constructor) {
    // Arrange
    // Act
    Fraction f(2);

    // Assert
    EXPECT_EQ(2, f.getNominator());
    EXPECT_EQ(1, f.getDenominator());
}

TEST_F(FractionTest, Can_Create_Fraction_With_Two_Parameter_constructor) {
    // Arrange
    // Act
    Fraction f(1, 2);

    // Assert
    EXPECT_EQ(1, f.getNominator());
    EXPECT_EQ(2, f.getDenominator());
}

TEST_F(FractionTest, Denominator_Cant_Be_Zero) {
    // Arrange
    Fraction f1(1, 1);

    // Act
    // Assert
    EXPECT_ANY_THROW(f1.setDenominator(0));
    EXPECT_ANY_THROW(Fraction f2(1, 0));
}

TEST_F(FractionTest, Can_Create_Fraction_With_Copy_Constructor) {
    // Arrange
    Fraction f1(1, 1);

    // Act
    Fraction f2(f1);

    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Equals_Fractions_Is_Equals) {
    // Arrange
    Fraction f1(7, 14);
    Fraction f2;

    // Act
    f2.setNominator(30);
    f2.setDenominator(60);

    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Different_Fractions_Is_Different) {
    // Arrange
    Fraction f1(45, 36);
    Fraction f2;

    // Act
    f2 = Fraction(7, 21);

    // Assert
    EXPECT_NE(f1, f2);
}

TEST_F(FractionTest, Different_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    // Assert
    EXPECT_NE(f1, f2);
}

TEST_F(FractionTest, NOD_Test) {
    // Arrange
    int a = -30;
    int b = -45;
    int c = 0;
    int d = 0;

    // Act
    c = nod(b, a);
    d = nod(a, b);

    // Assert
    EXPECT_EQ(c, 15);
    EXPECT_EQ(d, 15);
}

TEST_F(FractionTest, Denominator_Cant_Be_Negative) {
    // Arrange
    Fraction f1(1, -1);
    Fraction f2(1);

    // Act
    f2.setDenominator(-1);

    // Assert
    EXPECT_GT(f1.getDenominator(), 0);
    EXPECT_GT(f2.getDenominator(), 0);
}

TEST_F(FractionTest, Correct_Fraction_Reduction) {
    // Arrange
    Fraction f(5, 10);

    // Act
    f.fractionReduction();

    // Assert
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST_F(FractionTest, Addition_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 + f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), 2);
    EXPECT_EQ(f3.getDenominator(), 3);
}

TEST_F(FractionTest, Subtraction_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 - f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), -8);
    EXPECT_EQ(f3.getDenominator(), 15);
}

TEST_F(FractionTest, Multiplication_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 * f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), 1);
    EXPECT_EQ(f3.getDenominator(), 25);
}

TEST_F(FractionTest, Division_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 / f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), 1);
    EXPECT_EQ(f3.getDenominator(), 9);
}

TEST_F(FractionTest, Assignment_Test) {
    // Arrange
    Fraction f1(1, 1);

    // Act
    Fraction f2 = f1;

    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Addition_Fractions_With_Int_Test) {
    // Arrange
    Fraction f1(1, 15);
    int n = 5;

    // Act
    Fraction f2 = f1 + n;
    Fraction f3 = n + f1;

    // Assert
    EXPECT_EQ(f2, Fraction(76, 15));
    EXPECT_EQ(f3, Fraction(76, 15));
}

TEST_F(FractionTest, Subtraction_Fractions_With_Int_Test) {
    // Arrange
    Fraction f1(1, 15);
    int n = 5;

    // Act
    Fraction f2 = f1 - n;
    Fraction f3 = n - f1;

    // Assert
    EXPECT_EQ(f2, Fraction(-74, 15));
    EXPECT_EQ(f3, Fraction(74, 15));
}

TEST_F(FractionTest, Multiplication_Fractions_With_Int_Test) {
    // Arrange
    Fraction f1(1, 15);
    int n = 5;

    // Act
    Fraction f2 = f1 * n;
    Fraction f3 = n * f1;

    // Assert
    EXPECT_EQ(f2, Fraction(1, 3));
    EXPECT_EQ(f3, Fraction(1, 3));
}

TEST_F(FractionTest, Division_Fractions_With_Int_Test) {
    // Arrange
    Fraction f1(1, 15);
    int n = 5;

    // Act
    Fraction f2 = f1 / n;
    Fraction f3 = n / f1;

    // Assert
    EXPECT_EQ(f2, Fraction(1, 75));
    EXPECT_EQ(f3, Fraction(75, 1));
}

TEST_F(FractionTest, Fraction_To_Double_Test) {
    // Arrange
    Fraction f1(1, 15);

    // Act
    double d = static_cast<double>(1) / 15;

    // Assert
    EXPECT_NEAR(static_cast<double>(f1), d, FractionTest::epsilon);
}

TEST_F(FractionTest, Addition_Fractions_With_Double_Test) {
    // Arrange
    Fraction f1(1, 15);
    double n1 = 5.0;

    // Act
    double n2 = static_cast<double>(f1) + n1;
    double n3 = n1 + static_cast<double>(f1);

    // Assert
    EXPECT_NEAR(n2, 5.06667, FractionTest::epsilon);
    EXPECT_NEAR(n3, 5.06667, FractionTest::epsilon);
}

TEST_F(FractionTest, Subtraction_Fractions_With_Double_Test) {
    // Arrange
    Fraction f1(1, 15);
    double n = 5.0;

    // Act
    double n2 = static_cast<double>(f1) - n;
    double n3 = n - static_cast<double>(f1);

    // Assert
    EXPECT_NEAR(n2, -4.93334, FractionTest::epsilon);
    EXPECT_NEAR(n3, 4.93334, FractionTest::epsilon);
}

TEST_F(FractionTest, Multiplication_Fractions_With_Double_Test) {
    // Arrange
    Fraction f1(1, 15);
    double n = 5.0;

    // Act
    double n2 = static_cast<double>(f1) * n;
    double n3 = n * static_cast<double>(f1);

    // Assert
    EXPECT_NEAR(n2, 0.33334, FractionTest::epsilon);
    EXPECT_NEAR(n3, 0.33334, FractionTest::epsilon);
}

TEST_F(FractionTest, Division_Fractions_With_Double_Test) {
    // Arrange
    Fraction f1(1, 15);
    double n = 5.0;

    // Act
    double n2 = static_cast<double>(f1) / n;
    double n3 = n / static_cast<double>(f1);

    // Assert
    EXPECT_NEAR(n2, 0.01334, FractionTest::epsilon);
    EXPECT_NEAR(n3, 75, FractionTest::epsilon);
}

TEST_F(FractionTest, Operator_Double_Test) {
    // Arrange
    Fraction f1(1, 15);
    double n1 = static_cast<double>(1) / 15;

    // Act
    double n2 = f1;

    // Assert
    EXPECT_NEAR(n1, n2, FractionTest::epsilon);
}
