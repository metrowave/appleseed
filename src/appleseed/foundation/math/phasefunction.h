
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2017 Artem Bishev, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_FOUNDATION_MATH_PHASEFUNCTION_H
#define APPLESEED_FOUNDATION_MATH_PHASEFUNCTION_H

// appleseed.foundation headers.
#include "foundation/math/vector.h"

namespace foundation
{

class PhaseFunction
{
  public:
    virtual ~PhaseFunction() {}

    virtual float evaluate(const Vector3f& outgoing, const Vector3f& incoming) const = 0;
    virtual float sample(const Vector3f& outgoing, const Vector2f& s, Vector3f& incoming) const = 0;
};


//
// Henyey-Greenstein phase function.
//
// https://www.astro.umd.edu/~jph/HG_note.pdf
//

class HenyeyPhaseFunction
  : public PhaseFunction
{
  public:
    explicit HenyeyPhaseFunction(const float g);

    float evaluate(const Vector3f& outgoing, const Vector3f& incoming) const override;
    float sample(const Vector3f& outgoing, const Vector2f& s, Vector3f& incoming) const override;

  private:
    const float m_g;
};


//
// Isotropic phase function.
//

class IsotropicPhaseFunction
  : public PhaseFunction
{
  public:
    float evaluate(const Vector3f& outgoing, const Vector3f& incoming) const override;
    float sample(const Vector3f& outgoing, const Vector2f& s, Vector3f& incoming) const override;
};

}       // namespace foundation

#endif  // !APPLESEED_FOUNDATION_MATH_PHASEFUNCTION_H
