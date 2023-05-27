/*
 * Copyright (c) 2023 Netlore Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * This code is part of Njord (HTML, CSS Parser) Component
 * of Netlore project that can be found at the github
 * repository at:
 *  - https://github.com/netlore-org/netlore
 */

#ifndef __NETLORE_NJORD_CSS_PROPERTIES
#define __NETLORE_NJORD_CSS_PROPERTIES

typedef enum __css_properties_t {
	// CSS Overflow Module Level 4
	WebkitLineClamp, // More on: https://drafts.csswg.org/css-overflow-4/#propdef--webkit-line-clamp

	// CSS Basic User Interface Module Level 4
	AccentColor, // More on: https://drafts.csswg.org/css-ui-4/#propdef-accent-color

	// CSS Box Alignment Module Level 3
	AlignContent, // More on: https://drafts.csswg.org/css-align/#propdef-align-content

	// CSS Box Alignment Module Level 3
	AlignItems, // More on: https://drafts.csswg.org/css-align/#propdef-align-items

	// CSS Box Alignment Module Level 3
	AlignSelf, // More on: https://drafts.csswg.org/css-align/#propdef-align-self

	// CSS Inline Layout Module Level 3
	AlignmentBaseline, // More on: https://drafts.csswg.org/css-inline-3/#propdef-alignment-baseline

	// CSS Cascading and Inheritance Level 3
	All, // More on: https://drafts.csswg.org/css-cascade-3/#propdef-all

	// CSS Animations Level 1
	Animation, // More on: https://drafts.csswg.org/css-animations/#propdef-animation

	// CSS Animations Level 2
	AnimationComposition, // More on: https://drafts.csswg.org/css-animations-2/#propdef-animation-composition

	// CSS Animations Level 1
	AnimationDelay, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-delay

	// CSS Animations Level 1
	AnimationDirection, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-direction

	// CSS Animations Level 2
	AnimationDuration, // More on: https://drafts.csswg.org/css-animations-2/#propdef-animation-duration

	// CSS Animations Level 1
	AnimationFillMode, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-fill-mode

	// CSS Animations Level 1
	AnimationIterationCount, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-iteration-count

	// CSS Animations Level 1
	AnimationName, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-name

	// CSS Animations Level 1
	AnimationPlayState, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-play-state

	// Scroll-driven Animations
	AnimationRange, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-animation-range

	// Scroll-driven Animations
	AnimationRangeEnd, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-animation-range-end

	// Scroll-driven Animations
	AnimationRangeStart, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-animation-range-start

	// CSS Animations Level 2
	AnimationTimeline, // More on: https://drafts.csswg.org/css-animations-2/#propdef-animation-timeline

	// CSS Animations Level 1
	AnimationTimingFunction, // More on: https://drafts.csswg.org/css-animations/#propdef-animation-timing-function

	// CSS Basic User Interface Module Level 4
	Appearance, // More on: https://drafts.csswg.org/css-ui-4/#propdef-appearance

	// CSS Box Sizing Module Level 4
	AspectRatio, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-aspect-ratio

	// CSS 2.1
	Azimuth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-azimuth

	// CSS Transforms Module Level 2
	BackfaceVisibility, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-backface-visibility

	// CSS 2.1
	Background, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-background

	// CSS 2.1
	BackgroundAttachment, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-background-attachment

	// Compositing and Blending Level 1
	BackgroundBlendMode, // More on: https://drafts.fxtf.org/compositing-1/#propdef-background-blend-mode

	// CSS Backgrounds and Borders Module Level 3
	BackgroundClip, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-background-clip

	// CSS 2.1
	BackgroundColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-background-color

	// CSS 2.1
	BackgroundImage, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-background-image

	// CSS Backgrounds and Borders Module Level 3
	BackgroundOrigin, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-background-origin

	// CSS 2.1
	BackgroundPosition, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-background-position

	// CSS 2.1
	BackgroundRepeat, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-background-repeat

	// CSS Backgrounds and Borders Module Level 3
	BackgroundSize, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-background-size

	// CSS Inline Layout Module Level 3
	BaselineShift, // More on: https://drafts.csswg.org/css-inline-3/#propdef-baseline-shift

	// CSS Inline Layout Module Level 3
	BaselineSource, // More on: https://drafts.csswg.org/css-inline-3/#propdef-baseline-source

	// CSS Overflow Module Level 4
	BlockEllipsis, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-block-ellipsis

	// CSS Logical Properties and Values Level 1
	BlockSize, // More on: https://drafts.csswg.org/css-logical-1/#propdef-block-size

	// CSS Rhythmic Sizing
	BlockStep, // More on: https://drafts.csswg.org/css-rhythm/#propdef-block-step

	// CSS Rhythmic Sizing
	BlockStepAlign, // More on: https://drafts.csswg.org/css-rhythm/#propdef-block-step-align

	// CSS Rhythmic Sizing
	BlockStepInsert, // More on: https://drafts.csswg.org/css-rhythm/#propdef-block-step-insert

	// CSS Rhythmic Sizing
	BlockStepRound, // More on: https://drafts.csswg.org/css-rhythm/#propdef-block-step-round

	// CSS Rhythmic Sizing
	BlockStepSize, // More on: https://drafts.csswg.org/css-rhythm/#propdef-block-step-size

	// CSS Generated Content Module Level 3
	BookmarkLabel, // More on: https://drafts.csswg.org/css-content-3/#propdef-bookmark-label

	// CSS Generated Content Module Level 3
	BookmarkLevel, // More on: https://drafts.csswg.org/css-content-3/#propdef-bookmark-level

	// CSS Generated Content Module Level 3
	BookmarkState, // More on: https://drafts.csswg.org/css-content-3/#propdef-bookmark-state

	// CSS 2.1
	Border, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border

	// CSS Logical Properties and Values Level 1
	BorderBlock, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block

	// CSS Logical Properties and Values Level 1
	BorderBlockColor, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-color

	// CSS Logical Properties and Values Level 1
	BorderBlockEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-end

	// CSS Logical Properties and Values Level 1
	BorderBlockEndColor, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-end-color

	// CSS Logical Properties and Values Level 1
	BorderBlockEndStyle, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-end-style

	// CSS Logical Properties and Values Level 1
	BorderBlockEndWidth, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-end-width

	// CSS Logical Properties and Values Level 1
	BorderBlockStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-start

	// CSS Logical Properties and Values Level 1
	BorderBlockStartColor, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-start-color

	// CSS Logical Properties and Values Level 1
	BorderBlockStartStyle, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-start-style

	// CSS Logical Properties and Values Level 1
	BorderBlockStartWidth, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-start-width

	// CSS Logical Properties and Values Level 1
	BorderBlockStyle, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-style

	// CSS Logical Properties and Values Level 1
	BorderBlockWidth, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-block-width

	// CSS 2.1
	BorderBottom, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-bottom

	// CSS 2.1
	BorderBottomColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-bottom-color

	// CSS Backgrounds and Borders Module Level 3
	BorderBottomLeftRadius, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-bottom-left-radius

	// CSS Backgrounds and Borders Module Level 3
	BorderBottomRightRadius, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-bottom-right-radius

	// CSS 2.1
	BorderBottomStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-bottom-style

	// CSS 2.1
	BorderBottomWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-bottom-width

	// CSS Round Display Level 1
	BorderBoundary, // More on: https://drafts.csswg.org/css-round-display/#propdef-border-boundary

	// CSS 2.1
	BorderCollapse, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/tables.html#propdef-border-collapse

	// CSS 2.1
	BorderColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-color

	// CSS Logical Properties and Values Level 1
	BorderEndEndRadius, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-end-end-radius

	// CSS Logical Properties and Values Level 1
	BorderEndStartRadius, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-end-start-radius

	// CSS Backgrounds and Borders Module Level 3
	BorderImage, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-image

	// CSS Backgrounds and Borders Module Level 3
	BorderImageOutset, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-image-outset

	// CSS Backgrounds and Borders Module Level 3
	BorderImageRepeat, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-image-repeat

	// CSS Backgrounds and Borders Module Level 3
	BorderImageSlice, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-image-slice

	// CSS Backgrounds and Borders Module Level 3
	BorderImageSource, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-image-source

	// CSS Backgrounds and Borders Module Level 3
	BorderImageWidth, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-image-width

	// CSS Logical Properties and Values Level 1
	BorderInline, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline

	// CSS Logical Properties and Values Level 1
	BorderInlineColor, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-color

	// CSS Logical Properties and Values Level 1
	BorderInlineEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-end

	// CSS Logical Properties and Values Level 1
	BorderInlineEndColor, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-end-color

	// CSS Logical Properties and Values Level 1
	BorderInlineEndStyle, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-end-style

	// CSS Logical Properties and Values Level 1
	BorderInlineEndWidth, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-end-width

	// CSS Logical Properties and Values Level 1
	BorderInlineStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-start

	// CSS Logical Properties and Values Level 1
	BorderInlineStartColor, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-start-color

	// CSS Logical Properties and Values Level 1
	BorderInlineStartStyle, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-start-style

	// CSS Logical Properties and Values Level 1
	BorderInlineStartWidth, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-start-width

	// CSS Logical Properties and Values Level 1
	BorderInlineStyle, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-style

	// CSS Logical Properties and Values Level 1
	BorderInlineWidth, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-inline-width

	// CSS 2.1
	BorderLeft, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-left

	// CSS 2.1
	BorderLeftColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-left-color

	// CSS 2.1
	BorderLeftStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-left-style

	// CSS 2.1
	BorderLeftWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-left-width

	// CSS Backgrounds and Borders Module Level 3
	BorderRadius, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-radius

	// CSS 2.1
	BorderRight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-right

	// CSS 2.1
	BorderRightColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-right-color

	// CSS 2.1
	BorderRightStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-right-style

	// CSS 2.1
	BorderRightWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-right-width

	// CSS 2.1
	BorderSpacing, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/tables.html#propdef-border-spacing

	// CSS Logical Properties and Values Level 1
	BorderStartEndRadius, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-start-end-radius

	// CSS Logical Properties and Values Level 1
	BorderStartStartRadius, // More on: https://drafts.csswg.org/css-logical-1/#propdef-border-start-start-radius

	// CSS 2.1
	BorderStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-style

	// CSS 2.1
	BorderTop, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-top

	// CSS 2.1
	BorderTopColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-top-color

	// CSS Backgrounds and Borders Module Level 3
	BorderTopLeftRadius, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-top-left-radius

	// CSS Backgrounds and Borders Module Level 3
	BorderTopRightRadius, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-border-top-right-radius

	// CSS 2.1
	BorderTopStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-top-style

	// CSS 2.1
	BorderTopWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-top-width

	// CSS 2.1
	BorderWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-border-width

	// CSS 2.1
	Bottom, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-bottom

	// CSS Fragmentation Module Level 4
	BoxDecorationBreak, // More on: https://drafts.csswg.org/css-break-4/#propdef-box-decoration-break

	// CSS Backgrounds and Borders Module Level 3
	BoxShadow, // More on: https://drafts.csswg.org/css-backgrounds/#propdef-box-shadow

	// CSS Box Sizing Module Level 3
	BoxSizing, // More on: https://drafts.csswg.org/css-sizing-3/#propdef-box-sizing

	// CSS Line Grid Module Level 1
	BoxSnap, // More on: https://drafts.csswg.org/css-line-grid/#propdef-box-snap

	// CSS Fragmentation Module Level 4
	BreakAfter, // More on: https://drafts.csswg.org/css-break-4/#propdef-break-after

	// CSS Fragmentation Module Level 4
	BreakBefore, // More on: https://drafts.csswg.org/css-break-4/#propdef-break-before

	// CSS Fragmentation Module Level 4
	BreakInside, // More on: https://drafts.csswg.org/css-break-4/#propdef-break-inside

	// CSS 2.1
	CaptionSide, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/tables.html#propdef-caption-side

	// CSS Basic User Interface Module Level 4
	Caret, // More on: https://drafts.csswg.org/css-ui-4/#propdef-caret

	// CSS Basic User Interface Module Level 3 (CSS3 UI)
	CaretColor, // More on: https://drafts.csswg.org/css-ui-3/#propdef-caret-color

	// CSS Basic User Interface Module Level 4
	CaretShape, // More on: https://drafts.csswg.org/css-ui-4/#propdef-caret-shape

	// CSS Template Layout Module
	Chains, // More on: https://drafts.csswg.org/css-template/#chains0

	// CSS 2.1
	Clear, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-clear

	// CSS 2.1
	Clip, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visufx.html#propdef-clip

	// CSS Masking Module Level 1
	ClipPath, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-clip-path

	// CSS Masking Module Level 1
	ClipRule, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-clip-rule

	// CSS 2.1
	Color, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/colors.html#propdef-color

	// CSS Color Adjustment Module Level 1
	ColorAdjust, // More on: https://drafts.csswg.org/css-color-adjust-1/#propdef-color-adjust

	// Filter Effects Module Level 1
	ColorInterpolationFilters, // More on: https://drafts.fxtf.org/filter-effects-1/#propdef-color-interpolation-filters

	// CSS Color Adjustment Module Level 1
	ColorScheme, // More on: https://drafts.csswg.org/css-color-adjust-1/#propdef-color-scheme

	// CSS Multi-column Layout Module Level 1
	ColumnCount, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-count

	// CSS Multi-column Layout Module Level 1
	ColumnFill, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-fill

	// CSS Box Alignment Module Level 3
	ColumnGap, // More on: https://drafts.csswg.org/css-align/#propdef-column-gap

	// CSS Multi-column Layout Module Level 1
	ColumnRule, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-rule

	// CSS Multi-column Layout Module Level 1
	ColumnRuleColor, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-rule-color

	// CSS Multi-column Layout Module Level 1
	ColumnRuleStyle, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-rule-style

	// CSS Multi-column Layout Module Level 1
	ColumnRuleWidth, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-rule-width

	// CSS Multi-column Layout Module Level 1
	ColumnSpan, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-span

	// CSS Multi-column Layout Module Level 1
	ColumnWidth, // More on: https://drafts.csswg.org/css-multicol/#propdef-column-width

	// CSS Multi-column Layout Module Level 1
	Columns, // More on: https://drafts.csswg.org/css-multicol/#propdef-columns

	// CSS Containment Module Level 1
	Contain, // More on: https://drafts.csswg.org/css-contain-1/#propdef-contain

	// CSS Box Sizing Module Level 4
	ContainIntrinsicBlockSize, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-contain-intrinsic-block-size

	// CSS Box Sizing Module Level 4
	ContainIntrinsicHeight, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-contain-intrinsic-height

	// CSS Box Sizing Module Level 4
	ContainIntrinsicInlineSize, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-contain-intrinsic-inline-size

	// CSS Box Sizing Module Level 4
	ContainIntrinsicSize, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-contain-intrinsic-size

	// CSS Box Sizing Module Level 4
	ContainIntrinsicWidth, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-contain-intrinsic-width

	// CSS Containment Module Level 3
	Container, // More on: https://drafts.csswg.org/css-contain-3/#propdef-container

	// CSS Containment Module Level 3
	ContainerName, // More on: https://drafts.csswg.org/css-contain-3/#propdef-container-name

	// CSS Containment Module Level 3
	ContainerType, // More on: https://drafts.csswg.org/css-contain-3/#propdef-container-type

	// CSS 2.1
	Content, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-content

	// CSS Containment Module Level 2
	ContentVisibility, // More on: https://drafts.csswg.org/css-contain-2/#propdef-content-visibility

	// CSS Overflow Module Level 4
	Continue, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-continue

	// CSS 2.1
	CounterIncrement, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-counter-increment

	// CSS 2.1
	CounterReset, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-counter-reset

	// CSS Lists and Counters Module Level 3
	CounterSet, // More on: https://drafts.csswg.org/css-lists-3/#propdef-counter-set

	// CSS 2.1
	Cue, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-cue

	// CSS 2.1
	CueAfter, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-cue-after

	// CSS 2.1
	CueBefore, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-cue-before

	// CSS 2.1
	Cursor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/ui.html#propdef-cursor

	// CSS 2.1
	Direction, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-direction

	// CSS 2.1
	Display, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-display

	// CSS Inline Layout Module Level 3
	DominantBaseline, // More on: https://drafts.csswg.org/css-inline-3/#propdef-dominant-baseline

	// CSS 2.1
	Elevation, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-elevation

	// CSS 2.1
	EmptyCells, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/tables.html#propdef-empty-cells

	// CSS Fill and Stroke Module Level 3
	Fill, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill

	// CSS Fill and Stroke Module Level 3
	FillBreak, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-break

	// CSS Fill and Stroke Module Level 3
	FillColor, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-color

	// CSS Fill and Stroke Module Level 3
	FillImage, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-image

	// CSS Fill and Stroke Module Level 3
	FillOpacity, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-opacity

	// CSS Fill and Stroke Module Level 3
	FillOrigin, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-origin

	// CSS Fill and Stroke Module Level 3
	FillPosition, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-position

	// CSS Fill and Stroke Module Level 3
	FillRepeat, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-repeat

	// CSS Fill and Stroke Module Level 3
	FillRule, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-rule

	// CSS Fill and Stroke Module Level 3
	FillSize, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-fill-size

	// Filter Effects Module Level 1
	Filter, // More on: https://drafts.fxtf.org/filter-effects-1/#propdef-filter

	// CSS Flexible Box Layout Module Level 1
	Flex, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex

	// CSS Flexible Box Layout Module Level 1
	FlexBasis, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex-basis

	// CSS Flexible Box Layout Module Level 1
	FlexDirection, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex-direction

	// CSS Flexible Box Layout Module Level 1
	FlexFlow, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex-flow

	// CSS Flexible Box Layout Module Level 1
	FlexGrow, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex-grow

	// CSS Flexible Box Layout Module Level 1
	FlexShrink, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex-shrink

	// CSS Flexible Box Layout Module Level 1
	FlexWrap, // More on: https://drafts.csswg.org/css-flexbox-1/#propdef-flex-wrap

	// CSS 2.1
	Float, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-float

	// CSS Page Floats
	FloatDefer, // More on: https://drafts.csswg.org/css-page-floats/#propdef-float-defer

	// CSS Page Floats
	FloatOffset, // More on: https://drafts.csswg.org/css-page-floats/#propdef-float-offset

	// CSS Page Floats
	FloatReference, // More on: https://drafts.csswg.org/css-page-floats/#propdef-float-reference

	// Filter Effects Module Level 1
	FloodColor, // More on: https://drafts.fxtf.org/filter-effects-1/#propdef-flood-color

	// Filter Effects Module Level 1
	FloodOpacity, // More on: https://drafts.fxtf.org/filter-effects-1/#propdef-flood-opacity

	// CSS Template Layout Module
	Flow, // More on: https://drafts.csswg.org/css-template/#flow0

	// CSS Regions Module Level 1
	FlowFrom, // More on: https://drafts.csswg.org/css-regions/#propdef-flow-from

	// CSS Regions Module Level 1
	FlowInto, // More on: https://drafts.csswg.org/css-regions/#propdef-flow-into

	// CSS 2.1
	Font, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/fonts.html#propdef-font

	// CSS 2.1
	FontFamily, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/fonts.html#propdef-font-family

	// CSS Fonts Module Level 3
	FontFeatureSettings, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-feature-settings

	// CSS Fonts Module Level 3
	FontKerning, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-kerning

	// CSS Fonts Module Level 4
	FontLanguageOverride, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-language-override

	// CSS Fonts Module Level 4
	FontOpticalSizing, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-optical-sizing

	// CSS Fonts Module Level 4
	FontPalette, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-palette

	// CSS 2.1
	FontSize, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/fonts.html#propdef-font-size

	// CSS Fonts Module Level 3
	FontSizeAdjust, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-size-adjust

	// CSS Fonts Module Level 3
	FontStretch, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-stretch

	// CSS 2.1
	FontStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/fonts.html#propdef-font-style

	// CSS Fonts Module Level 3
	FontSynthesis, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-synthesis

	// CSS Fonts Module Level 4
	FontSynthesisSmallCaps, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-synthesis-small-caps

	// CSS Fonts Module Level 4
	FontSynthesisStyle, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-synthesis-style

	// CSS Fonts Module Level 4
	FontSynthesisWeight, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-synthesis-weight

	// CSS 2.1
	FontVariant, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/fonts.html#propdef-font-variant

	// CSS Fonts Module Level 4
	FontVariantAlternates, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-variant-alternates

	// CSS Fonts Module Level 3
	FontVariantCaps, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-variant-caps

	// CSS Fonts Module Level 3
	FontVariantEastAsian, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-variant-east-asian

	// CSS Fonts Module Level 4
	FontVariantEmoji, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-variant-emoji

	// CSS Fonts Module Level 3
	FontVariantLigatures, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-variant-ligatures

	// CSS Fonts Module Level 3
	FontVariantNumeric, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-variant-numeric

	// CSS Fonts Module Level 3
	FontVariantPosition, // More on: https://drafts.csswg.org/css-fonts-3/#propdef-font-variant-position

	// CSS Fonts Module Level 4
	FontVariationSettings, // More on: https://drafts.csswg.org/css-fonts-4/#propdef-font-variation-settings

	// CSS 2.1
	FontWeight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/fonts.html#propdef-font-weight

	// CSS Generated Content for Paged Media Module
	FootnoteDisplay, // More on: https://drafts.csswg.org/css-gcpm/#propdef-footnote-display

	// CSS Generated Content for Paged Media Module
	FootnotePolicy, // More on: https://drafts.csswg.org/css-gcpm/#propdef-footnote-policy

	// CSS Color Adjustment Module Level 1
	ForcedColorAdjust, // More on: https://drafts.csswg.org/css-color-adjust-1/#propdef-forced-color-adjust

	// CSS Box Alignment Module Level 3
	Gap, // More on: https://drafts.csswg.org/css-align/#propdef-gap

	// CSS Writing Modes Level 3
	GlyphOrientationVertical, // More on: https://drafts.csswg.org/css-writing-modes-3/#propdef-glyph-orientation-vertical

	// CSS Grid Layout Module Level 2
	Grid, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid

	// CSS Grid Layout Module Level 2
	GridArea, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-area

	// CSS Grid Layout Module Level 2
	GridAutoColumns, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-auto-columns

	// CSS Grid Layout Module Level 2
	GridAutoFlow, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-auto-flow

	// CSS Grid Layout Module Level 2
	GridAutoRows, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-auto-rows

	// CSS Grid Layout Module Level 2
	GridColumn, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-column

	// CSS Grid Layout Module Level 2
	GridColumnEnd, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-column-end

	// CSS Grid Layout Module Level 2
	GridColumnStart, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-column-start

	// CSS Grid Layout Module Level 2
	GridRow, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-row

	// CSS Grid Layout Module Level 2
	GridRowEnd, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-row-end

	// CSS Grid Layout Module Level 2
	GridRowStart, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-row-start

	// CSS Grid Layout Module Level 2
	GridTemplate, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-template

	// CSS Grid Layout Module Level 2
	GridTemplateAreas, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-template-areas

	// CSS Grid Layout Module Level 2
	GridTemplateColumns, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-template-columns

	// CSS Grid Layout Module Level 2
	GridTemplateRows, // More on: https://drafts.csswg.org/css-grid-2/#propdef-grid-template-rows

	// CSS Text Module Level 3
	HangingPunctuation, // More on: https://drafts.csswg.org/css-text-3/#propdef-hanging-punctuation

	// CSS 2.1
	Height, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-height

	// CSS Text Module Level 4
	HyphenateCharacter, // More on: https://drafts.csswg.org/css-text-4/#propdef-hyphenate-character

	// CSS Text Module Level 4
	HyphenateLimitChars, // More on: https://drafts.csswg.org/css-text-4/#propdef-hyphenate-limit-chars

	// CSS Text Module Level 4
	HyphenateLimitLast, // More on: https://drafts.csswg.org/css-text-4/#propdef-hyphenate-limit-last

	// CSS Text Module Level 4
	HyphenateLimitLines, // More on: https://drafts.csswg.org/css-text-4/#propdef-hyphenate-limit-lines

	// CSS Text Module Level 4
	HyphenateLimitZone, // More on: https://drafts.csswg.org/css-text-4/#propdef-hyphenate-limit-zone

	// CSS Text Module Level 3
	Hyphens, // More on: https://drafts.csswg.org/css-text-3/#propdef-hyphens

	// CSS Images Module Level 3
	ImageOrientation, // More on: https://drafts.csswg.org/css-images-3/#propdef-image-orientation

	// CSS Images Module Level 3
	ImageRendering, // More on: https://drafts.csswg.org/css-images-3/#propdef-image-rendering

	// CSS Images Module Level 4
	ImageResolution, // More on: https://drafts.csswg.org/css-images-4/#propdef-image-resolution

	// CSS Inline Layout Module Level 3
	InitialLetter, // More on: https://drafts.csswg.org/css-inline-3/#propdef-initial-letter

	// CSS Inline Layout Module Level 3
	InitialLetterAlign, // More on: https://drafts.csswg.org/css-inline-3/#propdef-initial-letter-align

	// CSS Inline Layout Module Level 3
	InitialLetterWrap, // More on: https://drafts.csswg.org/css-inline-3/#propdef-initial-letter-wrap

	// CSS Logical Properties and Values Level 1
	InlineSize, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inline-size

	// CSS Inline Layout Module Level 3
	InlineSizing, // More on: https://drafts.csswg.org/css-inline-3/#propdef-inline-sizing

	// CSS Basic User Interface Module Level 4
	InputSecurity, // More on: https://drafts.csswg.org/css-ui-4/#propdef-input-security

	// CSS Logical Properties and Values Level 1
	Inset, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset

	// CSS Logical Properties and Values Level 1
	InsetBlock, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset-block

	// CSS Logical Properties and Values Level 1
	InsetBlockEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset-block-end

	// CSS Logical Properties and Values Level 1
	InsetBlockStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset-block-start

	// CSS Logical Properties and Values Level 1
	InsetInline, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset-inline

	// CSS Logical Properties and Values Level 1
	InsetInlineEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset-inline-end

	// CSS Logical Properties and Values Level 1
	InsetInlineStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-inset-inline-start

	// Compositing and Blending Level 1
	Isolation, // More on: https://drafts.fxtf.org/compositing-1/#propdef-isolation

	// CSS Box Alignment Module Level 3
	JustifyContent, // More on: https://drafts.csswg.org/css-align/#propdef-justify-content

	// CSS Box Alignment Module Level 3
	JustifyItems, // More on: https://drafts.csswg.org/css-align/#propdef-justify-items

	// CSS Box Alignment Module Level 3
	JustifySelf, // More on: https://drafts.csswg.org/css-align/#propdef-justify-self

	// CSS 2.1
	Left, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-left

	// CSS 2.1
	LetterSpacing, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-letter-spacing

	// Filter Effects Module Level 1
	LightingColor, // More on: https://drafts.fxtf.org/filter-effects-1/#propdef-lighting-color

	// CSS Text Module Level 3
	LineBreak, // More on: https://drafts.csswg.org/css-text-3/#propdef-line-break

	// CSS Overflow Module Level 4
	LineClamp, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-line-clamp

	// CSS Line Grid Module Level 1
	LineGrid, // More on: https://drafts.csswg.org/css-line-grid/#propdef-line-grid

	// CSS 2.1
	LineHeight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-line-height

	// CSS Rhythmic Sizing
	LineHeightStep, // More on: https://drafts.csswg.org/css-rhythm/#propdef-line-height-step

	// CSS Text Module Level 4
	LinePadding, // More on: https://drafts.csswg.org/css-text-4/#propdef-line-padding

	// CSS Line Grid Module Level 1
	LineSnap, // More on: https://drafts.csswg.org/css-line-grid/#propdef-line-snap

	// CSS 2.1
	ListStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-list-style

	// CSS 2.1
	ListStyleImage, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-list-style-image

	// CSS 2.1
	ListStylePosition, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-list-style-position

	// CSS 2.1
	ListStyleType, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-list-style-type

	// CSS 2.1
	Margin, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-margin

	// CSS Logical Properties and Values Level 1
	MarginBlock, // More on: https://drafts.csswg.org/css-logical-1/#propdef-margin-block

	// CSS Logical Properties and Values Level 1
	MarginBlockEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-margin-block-end

	// CSS Logical Properties and Values Level 1
	MarginBlockStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-margin-block-start

	// CSS 2.1
	MarginBottom, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-margin-bottom

	// CSS Fragmentation Module Level 4
	MarginBreak, // More on: https://drafts.csswg.org/css-break-4/#propdef-margin-break

	// CSS Logical Properties and Values Level 1
	MarginInline, // More on: https://drafts.csswg.org/css-logical-1/#propdef-margin-inline

	// CSS Logical Properties and Values Level 1
	MarginInlineEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-margin-inline-end

	// CSS Logical Properties and Values Level 1
	MarginInlineStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-margin-inline-start

	// CSS 2.1
	MarginLeft, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-margin-left

	// CSS 2.1
	MarginRight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-margin-right

	// CSS 2.1
	MarginTop, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-margin-top

	// CSS Box Model Module Level 4
	MarginTrim, // More on: https://drafts.csswg.org/css-box-4/#propdef-margin-trim

	// SVG Markers
	Marker, // More on: https://svgwg.org/specs/markers/#MarkerProperty

	// SVG Markers
	MarkerEnd, // More on: https://svgwg.org/specs/markers/#MarkerEndProperty

	// SVG Markers
	MarkerKnockoutLeft, // More on: https://svgwg.org/specs/markers/#MarkerKnockoutLeftProperty

	// SVG Markers
	MarkerKnockoutRight, // More on: https://svgwg.org/specs/markers/#MarkerKnockoutRightProperty

	// SVG Markers
	MarkerMid, // More on: https://svgwg.org/specs/markers/#MarkerMidProperty

	// SVG Markers
	MarkerPattern, // More on: https://svgwg.org/specs/markers/#MarkerPatternProperty

	// SVG Markers
	MarkerSegment, // More on: https://svgwg.org/specs/markers/#MarkerSegmentProperty

	// CSS Lists and Counters Module Level 3
	MarkerSide, // More on: https://drafts.csswg.org/css-lists-3/#propdef-marker-side

	// SVG Markers
	MarkerStart, // More on: https://svgwg.org/specs/markers/#MarkerStartProperty

	// CSS Masking Module Level 1
	Mask, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask

	// CSS Masking Module Level 1
	MaskBorder, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border

	// CSS Masking Module Level 1
	MaskBorderMode, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border-mode

	// CSS Masking Module Level 1
	MaskBorderOutset, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border-outset

	// CSS Masking Module Level 1
	MaskBorderRepeat, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border-repeat

	// CSS Masking Module Level 1
	MaskBorderSlice, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border-slice

	// CSS Masking Module Level 1
	MaskBorderSource, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border-source

	// CSS Masking Module Level 1
	MaskBorderWidth, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-border-width

	// CSS Masking Module Level 1
	MaskClip, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-clip

	// CSS Masking Module Level 1
	MaskComposite, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-composite

	// CSS Masking Module Level 1
	MaskImage, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-image

	// CSS Masking Module Level 1
	MaskMode, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-mode

	// CSS Masking Module Level 1
	MaskOrigin, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-origin

	// CSS Masking Module Level 1
	MaskPosition, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-position

	// CSS Masking Module Level 1
	MaskRepeat, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-repeat

	// CSS Masking Module Level 1
	MaskSize, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-size

	// CSS Masking Module Level 1
	MaskType, // More on: https://drafts.fxtf.org/css-masking-1/#propdef-mask-type

	// CSS Logical Properties and Values Level 1
	MaxBlockSize, // More on: https://drafts.csswg.org/css-logical-1/#propdef-max-block-size

	// CSS 2.1
	MaxHeight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-max-height

	// CSS Logical Properties and Values Level 1
	MaxInlineSize, // More on: https://drafts.csswg.org/css-logical-1/#propdef-max-inline-size

	// CSS Overflow Module Level 4
	MaxLines, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-max-lines

	// CSS 2.1
	MaxWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-max-width

	// CSS Logical Properties and Values Level 1
	MinBlockSize, // More on: https://drafts.csswg.org/css-logical-1/#propdef-min-block-size

	// CSS 2.1
	MinHeight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-min-height

	// CSS Logical Properties and Values Level 1
	MinInlineSize, // More on: https://drafts.csswg.org/css-logical-1/#propdef-min-inline-size

	// CSS Box Sizing Module Level 4
	MinIntrinsicSizing, // More on: https://drafts.csswg.org/css-sizing-4/#propdef-min-intrinsic-sizing

	// CSS 2.1
	MinWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-min-width

	// Compositing and Blending Level 1
	MixBlendMode, // More on: https://drafts.fxtf.org/compositing-1/#propdef-mix-blend-mode

	// CSS Basic User Interface Module Level 4
	NavDown, // More on: https://drafts.csswg.org/css-ui-4/#propdef-nav-down

	// CSS Basic User Interface Module Level 4
	NavLeft, // More on: https://drafts.csswg.org/css-ui-4/#propdef-nav-left

	// CSS Basic User Interface Module Level 4
	NavRight, // More on: https://drafts.csswg.org/css-ui-4/#propdef-nav-right

	// CSS Basic User Interface Module Level 4
	NavUp, // More on: https://drafts.csswg.org/css-ui-4/#propdef-nav-up

	// CSS Images Module Level 3
	ObjectFit, // More on: https://drafts.csswg.org/css-images-3/#propdef-object-fit

	// CSS Images Module Level 3
	ObjectPosition, // More on: https://drafts.csswg.org/css-images-3/#propdef-object-position

	// Motion Path Module Level 1
	Offset, // More on: https://drafts.fxtf.org/motion-1/#propdef-offset

	// Motion Path Module Level 1
	OffsetAnchor, // More on: https://drafts.fxtf.org/motion-1/#propdef-offset-anchor

	// Motion Path Module Level 1
	OffsetDistance, // More on: https://drafts.fxtf.org/motion-1/#propdef-offset-distance

	// Motion Path Module Level 1
	OffsetPath, // More on: https://drafts.fxtf.org/motion-1/#propdef-offset-path

	// Motion Path Module Level 1
	OffsetPosition, // More on: https://drafts.fxtf.org/motion-1/#propdef-offset-position

	// Motion Path Module Level 1
	OffsetRotate, // More on: https://drafts.fxtf.org/motion-1/#propdef-offset-rotate

	// CSS Color Module Level 3
	Opacity, // More on: https://drafts.csswg.org/css-color-3/#opacity

	// CSS Display Module Level 3
	Order, // More on: https://drafts.csswg.org/css-display/#propdef-order

	// CSS 2.1
	Orphans, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/page.html#propdef-orphans

	// CSS 2.1
	Outline, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/ui.html#propdef-outline

	// CSS 2.1
	OutlineColor, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/ui.html#propdef-outline-color

	// CSS Basic User Interface Module Level 3 (CSS3 UI)
	OutlineOffset, // More on: https://drafts.csswg.org/css-ui-3/#propdef-outline-offset

	// CSS 2.1
	OutlineStyle, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/ui.html#propdef-outline-style

	// CSS 2.1
	OutlineWidth, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/ui.html#propdef-outline-width

	// CSS 2.1
	Overflow, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visufx.html#propdef-overflow

	// CSS Scroll Anchoring Module Level 1
	OverflowAnchor, // More on: https://drafts.csswg.org/css-scroll-anchoring/#propdef-overflow-anchor

	// CSS Overflow Module Level 3
	OverflowBlock, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-overflow-block

	// CSS Overflow Module Level 3
	OverflowClipMargin, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-overflow-clip-margin

	// CSS Overflow Module Level 4
	OverflowClipMarginBlock, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-block

	// CSS Overflow Module Level 4
	OverflowClipMarginBlockEnd, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-block-end

	// CSS Overflow Module Level 4
	OverflowClipMarginBlockStart, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-block-start

	// CSS Overflow Module Level 4
	OverflowClipMarginBottom, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-bottom

	// CSS Overflow Module Level 4
	OverflowClipMarginInline, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-inline

	// CSS Overflow Module Level 4
	OverflowClipMarginInlineEnd, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-inline-end

	// CSS Overflow Module Level 4
	OverflowClipMarginInlineStart, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-inline-start

	// CSS Overflow Module Level 4
	OverflowClipMarginLeft, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-left

	// CSS Overflow Module Level 4
	OverflowClipMarginRight, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-right

	// CSS Overflow Module Level 4
	OverflowClipMarginTop, // More on: https://drafts.csswg.org/css-overflow-4/#propdef-overflow-clip-margin-top

	// CSS Overflow Module Level 3
	OverflowInline, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-overflow-inline

	// CSS Text Module Level 3
	OverflowWrap, // More on: https://drafts.csswg.org/css-text-3/#propdef-overflow-wrap

	// CSS Overflow Module Level 3
	OverflowX, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-overflow-x

	// CSS Overflow Module Level 3
	OverflowY, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-overflow-y

	// CSS Overscroll Behavior Module Level 1
	OverscrollBehavior, // More on: https://drafts.csswg.org/css-overscroll-1/#propdef-overscroll-behavior

	// CSS Overscroll Behavior Module Level 1
	OverscrollBehaviorBlock, // More on: https://drafts.csswg.org/css-overscroll-1/#propdef-overscroll-behavior-block

	// CSS Overscroll Behavior Module Level 1
	OverscrollBehaviorInline, // More on: https://drafts.csswg.org/css-overscroll-1/#propdef-overscroll-behavior-inline

	// CSS Overscroll Behavior Module Level 1
	OverscrollBehaviorX, // More on: https://drafts.csswg.org/css-overscroll-1/#propdef-overscroll-behavior-x

	// CSS Overscroll Behavior Module Level 1
	OverscrollBehaviorY, // More on: https://drafts.csswg.org/css-overscroll-1/#propdef-overscroll-behavior-y

	// CSS 2.1
	Padding, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-padding

	// CSS Logical Properties and Values Level 1
	PaddingBlock, // More on: https://drafts.csswg.org/css-logical-1/#propdef-padding-block

	// CSS Logical Properties and Values Level 1
	PaddingBlockEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-padding-block-end

	// CSS Logical Properties and Values Level 1
	PaddingBlockStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-padding-block-start

	// CSS 2.1
	PaddingBottom, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-padding-bottom

	// CSS Logical Properties and Values Level 1
	PaddingInline, // More on: https://drafts.csswg.org/css-logical-1/#propdef-padding-inline

	// CSS Logical Properties and Values Level 1
	PaddingInlineEnd, // More on: https://drafts.csswg.org/css-logical-1/#propdef-padding-inline-end

	// CSS Logical Properties and Values Level 1
	PaddingInlineStart, // More on: https://drafts.csswg.org/css-logical-1/#propdef-padding-inline-start

	// CSS 2.1
	PaddingLeft, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-padding-left

	// CSS 2.1
	PaddingRight, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-padding-right

	// CSS 2.1
	PaddingTop, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/box.html#propdef-padding-top

	// CSS Paged Media Module Level 3
	Page, // More on: https://drafts.csswg.org/css-page-3/#propdef-page

	// CSS 2.1
	PageBreakAfter, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/page.html#propdef-page-break-after

	// CSS 2.1
	PageBreakBefore, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/page.html#propdef-page-break-before

	// CSS 2.1
	PageBreakInside, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/page.html#propdef-page-break-inside

	// CSS 2.1
	Pause, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-pause

	// CSS 2.1
	PauseAfter, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-pause-after

	// CSS 2.1
	PauseBefore, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-pause-before

	// CSS Transforms Module Level 2
	Perspective, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-perspective

	// CSS Transforms Module Level 2
	PerspectiveOrigin, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-perspective-origin

	// CSS 2.1
	Pitch, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-pitch

	// CSS 2.1
	PitchRange, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-pitch-range

	// CSS Box Alignment Module Level 3
	PlaceContent, // More on: https://drafts.csswg.org/css-align/#propdef-place-content

	// CSS Box Alignment Module Level 3
	PlaceItems, // More on: https://drafts.csswg.org/css-align/#propdef-place-items

	// CSS Box Alignment Module Level 3
	PlaceSelf, // More on: https://drafts.csswg.org/css-align/#propdef-place-self

	// CSS 2.1
	PlayDuring, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-play-during

	// CSS Basic User Interface Module Level 4
	PointerEvents, // More on: https://drafts.csswg.org/css-ui-4/#propdef-pointer-events

	// CSS 2.1
	Position, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-position

	// CSS Color Adjustment Module Level 1
	PrintColorAdjust, // More on: https://drafts.csswg.org/css-color-adjust-1/#propdef-print-color-adjust

	// Cascading Style Sheets Level 2 Revision 1 (CSS 2.1) Specification
	PropertyName, // More on: https://drafts.csswg.org/css2/#propdef-property-name

	// CSS 2.1
	Quotes, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/generate.html#propdef-quotes

	// CSS Regions Module Level 1
	RegionFragment, // More on: https://drafts.csswg.org/css-regions/#propdef-region-fragment

	// CSS Basic User Interface Module Level 3 (CSS3 UI)
	Resize, // More on: https://drafts.csswg.org/css-ui-3/#propdef-resize

	// CSS Speech Module Level 1
	Rest, // More on: https://drafts.csswg.org/css-speech-1/#propdef-rest

	// CSS Speech Module Level 1
	RestAfter, // More on: https://drafts.csswg.org/css-speech-1/#propdef-rest-after

	// CSS Speech Module Level 1
	RestBefore, // More on: https://drafts.csswg.org/css-speech-1/#propdef-rest-before

	// CSS 2.1
	Richness, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-richness

	// CSS 2.1
	Right, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-right

	// CSS Transforms Module Level 2
	Rotate, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-rotate

	// CSS Box Alignment Module Level 3
	RowGap, // More on: https://drafts.csswg.org/css-align/#propdef-row-gap

	// CSS Ruby Annotation Layout Module Level 1
	RubyAlign, // More on: https://drafts.csswg.org/css-ruby-1/#propdef-ruby-align

	// CSS Ruby Annotation Layout Module Level 1
	RubyMerge, // More on: https://drafts.csswg.org/css-ruby-1/#propdef-ruby-merge

	// CSS Ruby Annotation Layout Module Level 1
	RubyOverhang, // More on: https://drafts.csswg.org/css-ruby-1/#propdef-ruby-overhang

	// CSS Ruby Annotation Layout Module Level 1
	RubyPosition, // More on: https://drafts.csswg.org/css-ruby-1/#propdef-ruby-position

	// CSS Generated Content for Paged Media Module
	Running, // More on: https://drafts.csswg.org/css-gcpm/#propdef-running

	// CSS Transforms Module Level 2
	Scale, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-scale

	// CSS Overflow Module Level 3
	ScrollBehavior, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-scroll-behavior

	// CSS Scroll Snap Module Level 1
	ScrollMargin, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin

	// CSS Scroll Snap Module Level 1
	ScrollMarginBlock, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-block

	// CSS Scroll Snap Module Level 1
	ScrollMarginBlockEnd, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-block-end

	// CSS Scroll Snap Module Level 1
	ScrollMarginBlockStart, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-block-start

	// CSS Scroll Snap Module Level 1
	ScrollMarginBottom, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-bottom

	// CSS Scroll Snap Module Level 1
	ScrollMarginInline, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-inline

	// CSS Scroll Snap Module Level 1
	ScrollMarginInlineEnd, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-inline-end

	// CSS Scroll Snap Module Level 1
	ScrollMarginInlineStart, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-inline-start

	// CSS Scroll Snap Module Level 1
	ScrollMarginLeft, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-left

	// CSS Scroll Snap Module Level 1
	ScrollMarginRight, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-right

	// CSS Scroll Snap Module Level 1
	ScrollMarginTop, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-margin-top

	// CSS Scroll Snap Module Level 1
	ScrollPadding, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding

	// CSS Scroll Snap Module Level 1
	ScrollPaddingBlock, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-block

	// CSS Scroll Snap Module Level 1
	ScrollPaddingBlockEnd, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-block-end

	// CSS Scroll Snap Module Level 1
	ScrollPaddingBlockStart, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-block-start

	// CSS Scroll Snap Module Level 1
	ScrollPaddingBottom, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-bottom

	// CSS Scroll Snap Module Level 1
	ScrollPaddingInline, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-inline

	// CSS Scroll Snap Module Level 1
	ScrollPaddingInlineEnd, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-inline-end

	// CSS Scroll Snap Module Level 1
	ScrollPaddingInlineStart, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-inline-start

	// CSS Scroll Snap Module Level 1
	ScrollPaddingLeft, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-left

	// CSS Scroll Snap Module Level 1
	ScrollPaddingRight, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-right

	// CSS Scroll Snap Module Level 1
	ScrollPaddingTop, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-padding-top

	// CSS Scroll Snap Module Level 1
	ScrollSnapAlign, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-snap-align

	// CSS Scroll Snap Module Level 1
	ScrollSnapStop, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-snap-stop

	// CSS Scroll Snap Module Level 1
	ScrollSnapType, // More on: https://drafts.csswg.org/css-scroll-snap-1/#propdef-scroll-snap-type

	// Scroll-driven Animations
	ScrollTimeline, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-scroll-timeline

	// Scroll-driven Animations
	ScrollTimelineAttachment, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-scroll-timeline-attachment

	// Scroll-driven Animations
	ScrollTimelineAxis, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-scroll-timeline-axis

	// Scroll-driven Animations
	ScrollTimelineName, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-scroll-timeline-name

	// CSS Scrollbars Styling Module Level 1
	ScrollbarColor, // More on: https://drafts.csswg.org/css-scrollbars/#propdef-scrollbar-color

	// CSS Overflow Module Level 3
	ScrollbarGutter, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-scrollbar-gutter

	// CSS Scrollbars Styling Module Level 1
	ScrollbarWidth, // More on: https://drafts.csswg.org/css-scrollbars/#propdef-scrollbar-width

	// CSS Shapes Module Level 1
	ShapeImageThreshold, // More on: https://drafts.csswg.org/css-shapes/#propdef-shape-image-threshold

	// CSS Round Display Level 1
	ShapeInside, // More on: https://drafts.csswg.org/css-round-display/#propdef-shape-inside

	// CSS Shapes Module Level 1
	ShapeMargin, // More on: https://drafts.csswg.org/css-shapes/#propdef-shape-margin

	// CSS Shapes Module Level 1
	ShapeOutside, // More on: https://drafts.csswg.org/css-shapes/#propdef-shape-outside

	// CSS Spatial Navigation Level 1
	SpatialNavigationAction, // More on: https://drafts.csswg.org/css-nav-1/#propdef-spatial-navigation-action

	// CSS Spatial Navigation Level 1
	SpatialNavigationContain, // More on: https://drafts.csswg.org/css-nav-1/#propdef-spatial-navigation-contain

	// CSS Spatial Navigation Level 1
	SpatialNavigationFunction, // More on: https://drafts.csswg.org/css-nav-1/#propdef-spatial-navigation-function

	// CSS 2.1
	Speak, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-speak

	// CSS Speech Module Level 1
	SpeakAs, // More on: https://drafts.csswg.org/css-speech-1/#propdef-speak-as

	// CSS 2.1
	SpeakHeader, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-speak-header

	// CSS 2.1
	SpeakNumeral, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-speak-numeral

	// CSS 2.1
	SpeakPunctuation, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-speak-punctuation

	// CSS 2.1
	SpeechRate, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-speech-rate

	// CSS 2.1
	Stress, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-stress

	// CSS Generated Content Module Level 3
	StringSet, // More on: https://drafts.csswg.org/css-content-3/#propdef-string-set

	// CSS Fill and Stroke Module Level 3
	Stroke, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke

	// CSS Fill and Stroke Module Level 3
	StrokeAlign, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-align

	// SVG Strokes
	StrokeAlignment, // More on: https://svgwg.org/specs/strokes/#StrokeAlignmentProperty

	// CSS Fill and Stroke Module Level 3
	StrokeBreak, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-break

	// CSS Fill and Stroke Module Level 3
	StrokeColor, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-color

	// CSS Fill and Stroke Module Level 3
	StrokeDashCorner, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-dash-corner

	// CSS Fill and Stroke Module Level 3
	StrokeDashJustify, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-dash-justify

	// SVG Strokes
	StrokeDashadjust, // More on: https://svgwg.org/specs/strokes/#StrokeDashadjustProperty

	// CSS Fill and Stroke Module Level 3
	StrokeDasharray, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-dasharray

	// SVG Strokes
	StrokeDashcorner, // More on: https://svgwg.org/specs/strokes/#StrokeDashcornerProperty

	// CSS Fill and Stroke Module Level 3
	StrokeDashoffset, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-dashoffset

	// CSS Fill and Stroke Module Level 3
	StrokeImage, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-image

	// CSS Fill and Stroke Module Level 3
	StrokeLinecap, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-linecap

	// CSS Fill and Stroke Module Level 3
	StrokeLinejoin, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-linejoin

	// CSS Fill and Stroke Module Level 3
	StrokeMiterlimit, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-miterlimit

	// CSS Fill and Stroke Module Level 3
	StrokeOpacity, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-opacity

	// CSS Fill and Stroke Module Level 3
	StrokeOrigin, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-origin

	// CSS Fill and Stroke Module Level 3
	StrokePosition, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-position

	// CSS Fill and Stroke Module Level 3
	StrokeRepeat, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-repeat

	// CSS Fill and Stroke Module Level 3
	StrokeSize, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-size

	// CSS Fill and Stroke Module Level 3
	StrokeWidth, // More on: https://drafts.fxtf.org/fill-stroke/#propdef-stroke-width

	// CSS Text Module Level 3
	TabSize, // More on: https://drafts.csswg.org/css-text-3/#propdef-tab-size

	// CSS 2.1
	TableLayout, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/tables.html#propdef-table-layout

	// CSS 2.1
	TextAlign, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-text-align

	// CSS Text Module Level 3
	TextAlignAll, // More on: https://drafts.csswg.org/css-text-3/#propdef-text-align-all

	// CSS Text Module Level 3
	TextAlignLast, // More on: https://drafts.csswg.org/css-text-3/#propdef-text-align-last

	// CSS Text Module Level 4
	TextAutospace, // More on: https://drafts.csswg.org/css-text-4/#propdef-text-autospace

	// CSS Inline Layout Module Level 3
	TextBoxEdge, // More on: https://drafts.csswg.org/css-inline-3/#propdef-text-box-edge

	// CSS Inline Layout Module Level 3
	TextBoxTrim, // More on: https://drafts.csswg.org/css-inline-3/#propdef-text-box-trim

	// CSS Writing Modes Level 3
	TextCombineUpright, // More on: https://drafts.csswg.org/css-writing-modes-3/#propdef-text-combine-upright

	// CSS 2.1
	TextDecoration, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-text-decoration

	// CSS Text Decoration Module Level 3
	TextDecorationColor, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-decoration-color

	// CSS Text Decoration Module Level 3
	TextDecorationLine, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-decoration-line

	// CSS Text Decoration Module Level 4
	TextDecorationSkip, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-skip

	// CSS Text Decoration Module Level 4
	TextDecorationSkipBox, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-skip-box

	// CSS Text Decoration Module Level 4
	TextDecorationSkipInk, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-skip-ink

	// CSS Text Decoration Module Level 4
	TextDecorationSkipInset, // More on: https://www.w3.org/TR/2022/WD-css-text-decor-4-20220504/#propdef-text-decoration-skip-inset

	// CSS Text Decoration Module Level 4
	TextDecorationSkipSelf, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-skip-self

	// CSS Text Decoration Module Level 4
	TextDecorationSkipSpaces, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-skip-spaces

	// CSS Text Decoration Module Level 3
	TextDecorationStyle, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-decoration-style

	// CSS Text Decoration Module Level 4
	TextDecorationThickness, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-thickness

	// CSS Text Decoration Module Level 4
	TextDecorationTrim, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-decoration-trim

	// CSS Text Decoration Module Level 3
	TextEmphasis, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-emphasis

	// CSS Text Decoration Module Level 3
	TextEmphasisColor, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-emphasis-color

	// CSS Text Decoration Module Level 3
	TextEmphasisPosition, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-emphasis-position

	// CSS Text Decoration Module Level 4
	TextEmphasisSkip, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-emphasis-skip

	// CSS Text Decoration Module Level 3
	TextEmphasisStyle, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-emphasis-style

	// CSS Text Module Level 4
	TextGroupAlign, // More on: https://drafts.csswg.org/css-text-4/#propdef-text-group-align

	// CSS 2.1
	TextIndent, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-text-indent

	// CSS Text Module Level 3
	TextJustify, // More on: https://drafts.csswg.org/css-text-3/#propdef-text-justify

	// CSS Writing Modes Level 3
	TextOrientation, // More on: https://drafts.csswg.org/css-writing-modes-3/#propdef-text-orientation

	// CSS Overflow Module Level 3
	TextOverflow, // More on: https://drafts.csswg.org/css-overflow-3/#propdef-text-overflow

	// CSS Text Decoration Module Level 3
	TextShadow, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-shadow

	// CSS Text Module Level 4
	TextSpacing, // More on: https://drafts.csswg.org/css-text-4/#propdef-text-spacing

	// CSS Text Module Level 4
	TextSpacingTrim, // More on: https://drafts.csswg.org/css-text-4/#propdef-text-spacing-trim

	// CSS 2.1
	TextTransform, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-text-transform

	// CSS Text Decoration Module Level 4
	TextUnderlineOffset, // More on: https://drafts.csswg.org/css-text-decor-4/#propdef-text-underline-offset

	// CSS Text Decoration Module Level 3
	TextUnderlinePosition, // More on: https://drafts.csswg.org/css-text-decor-3/#propdef-text-underline-position

	// CSS Text Module Level 4
	TextWrap, // More on: https://drafts.csswg.org/css-text-4/#propdef-text-wrap

	// CSS 2.1
	Top, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-top

	// CSS Transforms Module Level 1
	Transform, // More on: https://drafts.csswg.org/css-transforms/#propdef-transform

	// CSS Transforms Module Level 1
	TransformBox, // More on: https://drafts.csswg.org/css-transforms/#propdef-transform-box

	// CSS Transforms Module Level 1
	TransformOrigin, // More on: https://drafts.csswg.org/css-transforms/#propdef-transform-origin

	// CSS Transforms Module Level 2
	TransformStyle, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-transform-style

	// CSS Transitions
	Transition, // More on: https://drafts.csswg.org/css-transitions/#propdef-transition

	// CSS Transitions
	TransitionDelay, // More on: https://drafts.csswg.org/css-transitions/#propdef-transition-delay

	// CSS Transitions
	TransitionDuration, // More on: https://drafts.csswg.org/css-transitions/#propdef-transition-duration

	// CSS Transitions
	TransitionProperty, // More on: https://drafts.csswg.org/css-transitions/#propdef-transition-property

	// CSS Transitions
	TransitionTimingFunction, // More on: https://drafts.csswg.org/css-transitions/#propdef-transition-timing-function

	// CSS Transforms Module Level 2
	Translate, // More on: https://drafts.csswg.org/css-transforms-2/#propdef-translate

	// CSS 2.1
	UnicodeBidi, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-unicode-bidi

	// CSS Basic User Interface Module Level 4
	UserSelect, // More on: https://drafts.csswg.org/css-ui-4/#propdef-user-select

	// CSS 2.1
	VerticalAlign, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-vertical-align

	// Scroll-driven Animations
	ViewTimeline, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-view-timeline

	// Scroll-driven Animations
	ViewTimelineAttachment, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-view-timeline-attachment

	// Scroll-driven Animations
	ViewTimelineAxis, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-view-timeline-axis

	// Scroll-driven Animations
	ViewTimelineInset, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-view-timeline-inset

	// Scroll-driven Animations
	ViewTimelineName, // More on: https://drafts.csswg.org/scroll-animations-1/#propdef-view-timeline-name

	// CSS View Transitions Module Level 1
	ViewTransitionName, // More on: https://drafts.csswg.org/css-view-transitions-1/#propdef-view-transition-name

	// CSS 2.1
	Visibility, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visufx.html#propdef-visibility

	// CSS Speech Module Level 1
	VoiceBalance, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-balance

	// CSS Speech Module Level 1
	VoiceDuration, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-duration

	// CSS 2.1
	VoiceFamily, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-voice-family

	// CSS Speech Module Level 1
	VoicePitch, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-pitch

	// CSS Speech Module Level 1
	VoiceRange, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-range

	// CSS Speech Module Level 1
	VoiceRate, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-rate

	// CSS Speech Module Level 1
	VoiceStress, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-stress

	// CSS Speech Module Level 1
	VoiceVolume, // More on: https://drafts.csswg.org/css-speech-1/#propdef-voice-volume

	// CSS 2.1
	Volume, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/aural.html#propdef-volume

	// CSS 2.1
	WhiteSpace, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-white-space

	// CSS Text Module Level 4
	WhiteSpaceCollapse, // More on: https://drafts.csswg.org/css-text-4/#propdef-white-space-collapse

	// CSS Text Module Level 4
	WhiteSpaceTrim, // More on: https://drafts.csswg.org/css-text-4/#propdef-white-space-trim

	// CSS 2.1
	Widows, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/page.html#propdef-widows

	// CSS 2.1
	Width, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visudet.html#propdef-width

	// CSS Will Change Module Level 1
	WillChange, // More on: https://drafts.csswg.org/css-will-change/#propdef-will-change

	// CSS Text Module Level 4
	WordBoundaryDetection, // More on: https://drafts.csswg.org/css-text-4/#propdef-word-boundary-detection

	// CSS Text Module Level 4
	WordBoundaryExpansion, // More on: https://drafts.csswg.org/css-text-4/#propdef-word-boundary-expansion

	// CSS Text Module Level 3
	WordBreak, // More on: https://drafts.csswg.org/css-text-3/#propdef-word-break

	// CSS 2.1
	WordSpacing, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/text.html#propdef-word-spacing

	// CSS Text Module Level 3
	WordWrap, // More on: https://drafts.csswg.org/css-text-3/#propdef-word-wrap

	// CSS Text Module Level 4
	WrapAfter, // More on: https://drafts.csswg.org/css-text-4/#propdef-wrap-after

	// CSS Text Module Level 4
	WrapBefore, // More on: https://drafts.csswg.org/css-text-4/#propdef-wrap-before

	// CSS Exclusions Module Level 1
	WrapFlow, // More on: https://drafts.csswg.org/css-exclusions/#propdef-wrap-flow

	// CSS Text Module Level 4
	WrapInside, // More on: https://drafts.csswg.org/css-text-4/#propdef-wrap-inside

	// CSS Exclusions Module Level 1
	WrapThrough, // More on: https://drafts.csswg.org/css-exclusions/#propdef-wrap-through

	// CSS Writing Modes Level 3
	WritingMode, // More on: https://drafts.csswg.org/css-writing-modes-3/#propdef-writing-mode

	// CSS 2.1
	ZIndex, // More on: http://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html#propdef-z-index
} css_properties_t;

css_properties_t njord_parse_css_property(char* css_string_property);

#endif /* __NETLORE_NJORD_CSS_PROPERTIES */